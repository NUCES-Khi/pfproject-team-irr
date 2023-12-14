#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double determinant(int n, int matrix[100][100]);

void readmatrixsize(char *filename, int *n_rows, int *n_cols)
{
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Error opening file to read matrix size.\n");
        exit(1);
    }

    *n_rows = 0, *n_cols = 0;
    char buffer[2048];
    char *token;
    int temp_num; 

    while(fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        (*n_rows)++;

        if (*n_rows == 1)
        {
            token = strtok(buffer, " \n");
            while (token != NULL)
            {
                (*n_cols)++; 
                token = strtok(NULL, " \n"); 
            }
        }
    }
    fclose(fptr);
}

int main()
{
    int size, n_rows = 0, n_cols = 0;
    int matrix[100][100];
    char filename[100];

    printf("Enter size of matrix: ");
    scanf("%d", &size);

    printf("Enter file name: ");
    scanf("%s", &filename);

    printf("Rows: %d, Cols= %d\n", n_rows, n_cols);
    readmatrixsize(filename, &n_rows, &n_cols);
    printf("Rows: %d, Cols= %d\n", n_rows, n_cols);

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

double determinant(int n, int matrix[100][100])
{
    double det = 0;

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
        int submatrix[100][100]; //declaration of sub matrix 

        for (int skipIndex = 0; skipIndex < n; skipIndex++) //run loop for rows of except the row which has to be skipped
        {
            int s_i = 0; //index for rows of sub matrix
            for (int i = 1; i < n; i++) //run loop for rows of the original matrix 
            {
                int s_j = 0; //index for columns of sub matrix 
                for (int j = 0; j < n; j++) //run loop for columns of the original matrix
                {
                    if (j == skipIndex)
                    {
                        continue; //if the j index is equal to the index that has to be skipped then that index will not be stored in the submatrix
                    }
                    else
                    {
                        submatrix[s_i][s_j] = matrix[i][j]; //store value of original matrix in the sub matrix
                        s_j++; //increment the column index of the sub matrix
                    }
                }
                s_i++; //increment the row index of the sub matrix
            }

            //variable used to determine what sign will be used with the cofactor (either +ve or -ve)
            int sign; 
            
            if (skipIndex % 2 == 0)
            {
                sign = 1;
            }
            else 
            {
                sign = -1;
            }

            det = det + matrix[0][skipIndex] * (determinant(n-1, submatrix) * sign);
        }
    }
    return det;
}
