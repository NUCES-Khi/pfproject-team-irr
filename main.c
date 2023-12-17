/*
*   Programmers:Ibrahim Johar Farooqi, Syeda Rija Ali, Riya Bhart
*   Description: main.c file for MATRICES CALCULATION PROGRAMME
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//function prototypes for start screen interface
void headMessage(const char* title);
void start();
void menu();

//function prototypes for allocating matrices & initialising matrices
int **creatematrix(char *filename, int n_rows, int n_cols);
void readmatrixsize(char *filename, int *n_rows, int *n_cols);

//function prototypes for matrices calculations
void matrixAddition(int m, int n, int **arr1,  int **arr2);
void matrixSubtraction(int m, int n, int **arr1,  int **arr2);
int **multiplyMatrices(int **matrix1, int rows1, int columns1, int **matrix2, int rows2, int columns2);
double determinant(int n, int **matrix);
void transposeM(int m, int n, int **matrix);
void fillKernel(int kernel[100][100], int n);
void convolution(int **matrix_con, int kernel[100][100], int n);

//main function start
int main()
{
    //function calls for start screen
    start();
    menu(); 

    //declaration of variables used in each case below
    char option;
    printf("\n");
    int n_rows;
    int n_cols;
    int rows_1;
    int cols_1;
    int rows_2;
    int cols_2;

    //declaration of variable to store filename of each .csv holding raw data of matrix
    char filename[100];

    while(1)
    {
        //input prompt
        printf("\n\t\t\t Press Menu Number to continue('0' to exit): ");
        scanf(" %c", &option);
        printf("\n");

        if (option == '0') //exit program if 0 is input from user
        {
            break;
        }

        //use of switch statement
        switch (option)
        {
            //case 1 for addition between two matrices
            case '1':
                
                //initialising variables to 0
                n_rows = 0, rows_1 = 0, rows_2 = 0; 
                n_cols = 0, cols_1 = 0, cols_2 = 0;
                
                //declaring 2d matrices
                int **matrix1_add;
                int **matrix2_add;

                //initialising filename to null
                filename[0] = '\0';

                //initialising matrix 1 from file 1
                printf("\n\t\t\t Enter file name for matrix 1: ");
                scanf("%s", filename);
                readmatrixsize(filename, &n_rows, &n_cols);
                rows_1 = n_rows;
                cols_1 = n_cols;
                matrix1_add = creatematrix(filename, rows_1, cols_1);
                
                //initialising matrix 2 from file 2
                filename[0] = '\0';
                printf("\n\t\t\t Enter file name for matrix 2: ");
                scanf("%s", filename);
                readmatrixsize(filename, &n_rows, &n_cols);
                rows_2 = n_rows;
                cols_2 = n_cols;
                matrix2_add = creatematrix(filename, rows_2, cols_2);

                //check if the size of both matrices is the same
                if (rows_1 == rows_2 && cols_1 == cols_2)
                {
                    matrixAddition(n_rows, n_cols, matrix1_add, matrix2_add);
                }
                else
                {
                    printf("\n\t\t\t Size of both matrices are not equal for calculation to proceed.");
                }
                
                //free memory of matrix 1
                for (int i = 0; i < rows_1; i++)
                {
                    free(matrix1_add[i]);
                }
                free(matrix1_add);

                //free memory of matrix 2
                for (int i = 0; i < rows_2; i++)
                {
                    free(matrix2_add[i]);
                }
                free(matrix2_add);
                break;

            //case 2 for subtraction between two matrices
            case '2':
                
                //initialising variables to 0
                n_rows = 0, rows_1 = 0, rows_2 = 0; 
                n_cols = 0, cols_1 = 0, cols_2 = 0;

                //declaring 2d matrices
                int **matrix1_sub;
                int **matrix2_sub;

                //initialising filename to null
                filename[0] = '\0';

                //initialising matrix 1 from file 1
                printf("\n\t\t\t Enter file name for matrix 1: ");
                scanf("%s", filename);
                readmatrixsize(filename, &n_rows, &n_cols);
                rows_1 = n_rows;
                cols_1 = n_cols;
                matrix1_sub = creatematrix(filename, rows_1, cols_1);
                
                //initialising matrix 2 from file 2
                filename[0] = '\0';
                printf("\n\t\t\t Enter file name for matrix 2: ");
                scanf("%s", filename);
                readmatrixsize(filename, &n_rows, &n_cols);
                rows_2 = n_rows;
                cols_2 = n_cols;
                matrix2_sub = creatematrix(filename, rows_2, cols_2);

                //check if the size of both matrices is the same
                if (rows_1 == rows_2 && cols_1 == cols_2)
                {
                    matrixSubtraction(n_rows, n_cols, matrix1_sub, matrix2_sub);
                }
                else
                {
                    printf("\n\t\t\t Size of both matrices are not equal for calculation to proceed.");
                }
                
                //free memory of matrix 1
                for (int i = 0; i < rows_1; i++)
                {
                    free(matrix1_sub[i]);
                }
                free(matrix1_sub);

                //free memory of matrix 2
                for (int i = 0; i < rows_2; i++)
                {
                    free(matrix2_sub[i]);
                }
                free(matrix2_sub);
                break;

            //case 3 for multiplication between two matrices
            case '3':

                //initialising variables to 0
                n_rows = 0, rows_1 = 0, rows_2 = 0; 
                n_cols = 0, cols_1 = 0, cols_2 = 0;

                //declaring 2d matrices
                int **matrix1_mul;
                int **matrix2_mul;

                //initialising filename to null
                filename[0] = '\0';
                printf("\n\t\t\t Enter file name for matrix 1: ");
                scanf("%s", filename);

                //initialising matrix 1 from file 1
                readmatrixsize(filename, &n_rows, &n_cols);
                rows_1 = n_rows;
                cols_1 = n_cols;
                matrix1_mul = creatematrix(filename, rows_1, cols_1);

                //initialising filename to null
                filename[0] = '\0';
                printf("\n\t\t\t Enter file name for matrix 2: ");
                scanf("%s", filename);

                //initialising matrix 2 from file 2
                readmatrixsize(filename, &n_rows, &n_cols);
                rows_2 = n_rows;
                cols_2 = n_cols;
                matrix2_mul = creatematrix(filename, rows_2, cols_2);

                //result calculation call to multiplication function
                int **result = multiplyMatrices(matrix1_mul, rows_1, cols_1, matrix2_mul, rows_2, cols_2);
                
                //printing of resultant matrix
                printf("\n\n\t\t\t RESULTANT MATRIX OF MULTIPLICATION PERFORMED\n");
                for (int i = 0; i < rows_1; i++)
                {
                    printf("\n\t\t\t\t\t");
                    for (int j = 0; j < cols_2; j++)
                    {
                        printf("%d  ", result[i][j]);
                    }
                    printf("\n");
                }

                //free memory of resultant matrix
                for (int i = 0; i < rows_1; i++)
                {
                    free(result[i]);
                }
                free(result);

                //free memory of matrix 1
                for (int i = 0; i < rows_1; i++)
                {
                    free(matrix1_mul[i]);
                }
                free(matrix1_mul);

                //free memory of matrix 2
                for (int i = 0; i < rows_2; i++)
                {
                    free(matrix2_mul[i]);
                }
                free(matrix2_mul);
                break;
            
            //case 4 for calculating determinant of a matrix
            case '4':

                //initialising variables to 0
                n_rows = 0; 
                n_cols = 0;

                //declaring 2d matrix
                int **matrix;

                //initialising filename to null
                filename[0] = '\0';
                printf("\n\t\t\t Enter file name: ");
                scanf("%s", filename);

                //initialising 2d matrix
                readmatrixsize(filename, &n_rows, &n_cols);    
                matrix = creatematrix(filename, n_rows, n_cols);

                //check if matrix is square matrix or not
                if (n_rows != n_cols)
                {
                    printf("\t\t\t Determinant cannot be calculated since the matrix is not a square matrix.\n");
                }
                else
                {
                    printf("\t\t\t The determinant of the matrix is: %.2lf", determinant(n_rows, matrix));
                }

                //free memory of 2d array
                for (int i = 0; i < n_rows; i++)
                {
                    free(matrix[i]);
                }
                free(matrix);
                break;

            //case 5 for calculating transpose of a matrix
            case '5':
                
                //initialising variables to 0
                n_rows = 0; 
                n_cols = 0;

                //declaring 2d matrix
                int **matrix_tran;

                //initialising filename to null
                filename[0] = '\0';
                printf("\n\t\t\t Enter file name: ");
                scanf("%s", filename);

                //initialising matrix from file
                readmatrixsize(filename, &n_rows, &n_cols);
                matrix_tran = creatematrix(filename, n_rows, n_cols);
                transposeM(n_rows, n_cols, matrix_tran);

                //free memory
                for (int i = 0; i < n_rows; i++)
                {
                    free(matrix_tran[i]);
                }
                free(matrix_tran);
                break;
            //case 6 for the calculation of the convolution of a matrix
            case '6':

                //initialising variables to 0
                n_rows = 0;
                n_cols = 0;

                //declaring of a 2d matrix
                int **matrix_con;

                //initialising the filename to null
                filename[0] = '\0';
                printf("\n\t\t\t Enter file name: ");
                scanf("%s", filename);

                //initialising the matrix from the file
                readmatrixsize(filename, &n_rows, &n_cols);
                matrix_con = creatematrix(filename, n_rows, n_cols);
                
                //declaring the kernel
                int kernel[100][100];
                fillKernel(kernel, n_rows);

                //printing the result of the convolution
                printf("\t\t\t Convolution result:\n");
                convolution(matrix_con, kernel, n_rows);

                //free memory of the matrix
                for (int i = 0; i < n_rows; i++)
                {
                    free(matrix_con[i]);
                }
                free(matrix_con);                
                break;
            default:
                printf("\t\t\t Enter valid number from list.\n");
                break;
        }//end of switch statement
    }
    return 0;
}//end main()

//function definition of fillKernel
void fillKernel(int kernel[100][100], int n) {
    printf("\t\t\t Enter the kernel matrix:\n");
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            printf("\t\t\t ");
            scanf("%d", &kernel[i][j]);
            if (kernel[i][j] != 0 && kernel[i][j] != 1 && kernel[i][j] != -1) {
                printf("\t\t\t Invalid input. Please enter a valid integer (0, 1, or -1).\n");
                return;
            }
        }
    }
}

//function definition of the calculation of convolution
void convolution(int **matrix_con, int kernel[100][100], int n) {
    if (n < 3) {
        printf("\t\t\t Matrix size should be at least 3x3 for convolution.\n");
        return;
    }

    int result[100][100];

    for (int i = 0; i < n - 2; i++)
    {
        printf("\n\t\t\t ");
        for (int j = 0; j < n - 2; j++) {
            result[i][j] = 0;

            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++) {
                    int matrixRow = i + x;
                    int matrixCol = j + y;

                    if (matrixRow >= 0 && matrixRow < n && matrixCol >= 0 && matrixCol < n) {
                        result[i][j] += matrix_con[matrixRow][matrixCol] * kernel[x][y];
                    }
                }
            }

            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

//function definition for the calculation of the transpose
void transposeM(int m, int n, int **matrix)
{
    printf("\n\n\t\t\t TRANSPOSE OF MATRIX:\n");
    for(int i=0; i<n; i++)
    {
        printf("\n\t\t\t ");
        for(int j=0; j<m; j++)
        {
            printf("%02d  ", matrix[j][i]);
        }
        printf("\n");
    }    
}

//function definition for the multiplication between two matrices
int **multiplyMatrices(int **matrix1, int rows1, int columns1, int **matrix2, int rows2, int columns2)
{
    if (columns1 != rows2)
    {
        printf("Matrices cannot be multiplied!\n");
        return NULL;
    }

    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++)
    {
        result[i] = (int *)malloc(columns2 * sizeof(int));
    }

    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < columns2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

//function definition for the subtraction between two matrices
void matrixSubtraction(int m, int n, int **arr1,  int **arr2)
{
    int **arrfinal = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        arrfinal[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arrfinal[i][j] = arr1[i][j] - arr2[i][j];
        }
    }

    printf("\n\n\t\t\t RESULTANT MATRIX OF SUBTRACTION PERFORMED\n");
    for (int i = 0; i < m; i++)
    {
        printf("\n\t\t\t ");
        for (int j = 0; j < n; j++)
        {
            printf("%02d  ", arrfinal[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        free(arrfinal[i]);
    }
    free(arrfinal);
}

//function definition for the addition between two matrices
void matrixAddition(int m, int n, int **arr1,  int **arr2)
{
    int **arrfinal = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        arrfinal[i] = (int *)malloc(n * sizeof(int));
    }   

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arrfinal[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("\n\n\t\t\t RESULTANT MATRIX OF ADDITION PERFORMED\n");
    for (int i = 0; i < m; i++)
    {
        printf("\n\t\t\t ");
        for (int j = 0; j < n; j++)
        {
            printf("%02d  ", arrfinal[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        free(arrfinal[i]);
    }
    free(arrfinal);
}

//fucntion definition for the calculation of the determinant of a matrix
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


//function definition for the creation of matrix
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

//function definition for the reading of the size of the matrix
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

//function definition for the menu
void menu()
{
    printf("\n\n\n\t\t\t---------------------------------------------");
    printf("\n\t\t\t|          PROGRAM FUNCTIONALITIES          |");
    printf("\n\t\t\t---------------------------------------------");
    printf("\n\t\t\t|   |1| Addition between TWO Matrices       |");
    printf("\n\t\t\t|   |2| Subtraction between TWO Matrices    |");
    printf("\n\t\t\t|   |3| Multiplication between TWO Matrices |");
    printf("\n\t\t\t|   |4| Determinant of a Matrix             |");
    printf("\n\t\t\t|   |5| Transpose of a Matrix               |");
    printf("\n\t\t\t|   |6| Convolution of a Matrix             |");
    printf("\n\t\t\t|   |0| Exit                                |");    
    printf("\n\t\t\t---------------------------------------------");

}

//function definition for the headmessage
void headMessage(const char* title)
{
    system("cls");  
    printf("\n\t\t\t#############################################");
    printf("\n\t\t\t#                                           #");
    printf("\n\t\t\t# WELCOME TO MATRICES CALCULATION PROGRAMME #");
    printf("\n\t\t\t#                                           #");
    printf("\n\t\t\t#############################################");
    printf("\n\t\t\t---------------------------------------------");
    printf("\n\t\t\t\t\t %s", title);
    printf("\n\t\t\t---------------------------------------------");
    printf("\n\t\t\t     Rija Ali - Riya Bhart - Ibrahim Johar");
    printf("\n\t\t\t---------------------------------------------");
}

//function definition for the start message
void start()
{
    headMessage("PF PROJECT");
    printf("\n");
    printf("\n\t\t\t*********************************************\n");
    printf("\n\t\t\t    ====================================");
    printf("\n\t\t\t    *           LET'S START!           *");
    printf("\n\t\t\t    ====================================");
    printf("\n\n\t\t\t*********************************************\n");
    printf("\n\n\t\t\t\t   Press Enter to begin...");
    getch();
}

//end of file
