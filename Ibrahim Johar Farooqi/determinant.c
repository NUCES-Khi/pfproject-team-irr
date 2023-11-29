#include <stdio.h>

int determinant(int n, int matrix[100][100]);

int main()
{
    int size;
    int matrix[100][100];

    printf("Enter size of matrix: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("Enter value in [%d][%d]: ", i,j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The determinant of the function is: %d", determinant(size, matrix));

}

int determinant(int n, int matrix[100][100])
{
    int det = 0;

    //base case
    if (n==1)
    {
        return matrix[0][0];
    }
    //second base case
    if (n==2)
    {
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]); 
    } 
    //recursive case
    else
    {
        int submatrix[100][100];

        for (int skipIndex = 0; skipIndex < n; skipIndex++)
        {
            int s_i = 0;
            for (int i = 1; i < n; i++)
            {
                int s_j = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == skipIndex)
                    {
                        continue;
                    }
                    else
                    {
                        submatrix[s_i][s_j] = matrix[i][j];
                        s_j++;
                    }
                }
                s_i++;
            }

            int sign;
            if (skipIndex % 2 == 0)
            {
                sign = 1;
            }
            else 
            {
                sign = -1;
            }

            det = det + matrix[0][skipIndex] * determinant(n-1, submatrix) * sign;
        }
    }
    return det;
}
