#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double determinant(int n, int **matrix);
int **creatematrix(char *filename, int n_rows, int n_cols);
void readmatrixsize(char *filename, int *n_rows, int *n_cols);

int main() //main for determinant
{
    int size, n_rows = 0, n_cols = 0;
    int **matrix;
    char filename[100];

    printf("Enter file name: ");
    scanf("%s", &filename);

    printf("Rows: %d, Cols= %d\n", n_rows, n_cols);
    readmatrixsize(filename, &n_rows, &n_cols);
    printf("Rows: %d, Cols= %d\n", n_rows, n_cols);
    


    matrix = creatematrix(filename, n_rows, n_cols);
    printf("Matrix:\n");
    for (int i = 0; i < n_rows; i++)
    {
        for (int j = 0; j < n_cols; j++)
        {
            printf("%02d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    if (n_rows != n_cols)
    {
        printf("Determinant cannot be calculated since the matrix is not a square matrix.\n");
    }
    else
    {
        printf("The determinant of the matrix is: %.2lf", determinant(n_rows, matrix));
    }

    for (int i = 0; i < n_rows; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

}

void readmatrixsize(char *filename, int *n_rows, int *n_cols)
{
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Error opening file. error in function: [readmatrixsize]\n");
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
            token = strtok(buffer, ",");
            while (token != NULL)
            {
                (*n_cols)++; 
                token = strtok(NULL, ","); 
            }
        }
    }

    fclose(fptr);
}


int **creatematrix(char *filename, int n_rows, int n_cols)
{
    FILE *fptr = fopen(filename, "r");

    if (fptr == NULL)
    {
        printf("Error opening file. error in function: [creatematrix]\n");
        exit(1);
    }

    int **matrix = malloc(n_rows * sizeof(int *));

    for (int i = 0; i < n_rows; i++)
    {
        matrix[i] = malloc(n_cols * sizeof(int));

        char buffer[1024];
        if (fgets(buffer, sizeof(buffer), fptr) == NULL)
        {
            printf("Error reading file. error in function: [creatematrix]\n");
            exit(1);
        }

        char *token_val = strtok(buffer, ",");
        for (int j = 0; j < n_cols; j++)
        {
            matrix[i][j] = atoi(token_val);
            token_val = strtok(NULL, ",");
        }
    }

    fclose(fptr);

    return matrix;
}


double determinant(int n, int **matrix)
{
    double det = 0;
    int **submatrix; //declaration of sub matrix 

    submatrix = malloc(n * sizeof(int *));
    for(int i = 0; i < n; i++)
    {
        submatrix[i] = malloc(n * sizeof(int));
    }

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

    //free submatrix memory
    for(int i = 0; i < n; i++)
    {
        free(submatrix[i]);
    }
    free(submatrix);
    return det;
}
