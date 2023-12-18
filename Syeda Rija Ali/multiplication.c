/*
The code below is completed now by using functions and DMA.
*/

#include <stdio.h>
#include <stdlib.h>

//Function prototype
int **allocateMatrix(int rows, int columns);
int **multiplyMatrices(int **matrix1, int rows1, int columns1, int **matrix2, int rows2, int columns2);
void freeMatrix(int **matrix, int rows);


int main() {
    int m, n, p, q; /* where: m=row1 , n=column1 , p=row2, q=column2*/

    // Input dimensions
    printf("Enter the dimensions of the first matrix (mxn): ");
    scanf("%d %d", &m, &n);

    int **arr1 = allocateMatrix(m, n);
    
   
    // Input dimensions of the second matrix
    printf("Enter the dimensions of the second matrix (pxq): ");
    scanf("%d %d", &p, &q);

    int **arr2 = allocateMatrix(p, q);


    // Check if matrices can be multiplied
    if (n != p) {
        printf("The dimensions of the matrices are different and cannot be multiplied!\n");
        return 1;
    }
    
 // Input first matrix
    printf("Enter elements of the first matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

    // Input second matrix
    printf("Enter elements of the second matrix:\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

    // Performing matrix multiplication
    int **ans = multiplyMatrices(arr1, m, n, arr2, p, q);

    // Displaying answer
    if (ans != NULL) {
        printf("Resultant matrix after multiplication:\n");
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < q; j++) {
                printf("%d ", ans[i][j]);
            }
            printf("\n");
        }

        // Freeing dynamically allocated memory
        freeMatrix(arr1, m);
        freeMatrix(arr2, p);
        freeMatrix(ans, m);
    }

    return 0;
}



// Function to dynamically allocate memory for a 2D array
int **allocateMatrix(int rows, int columns) {
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }
    return matrix;
}

// Function to perform matrix multiplication
int **multiplyMatrices(int **matrix1, int rows1, int columns1, int **matrix2, int rows2, int columns2) {
    if (columns1 != rows2) {
        printf("Matrices cannot be multiplied!\n");
        return NULL;
    }

    int **result = allocateMatrix(rows1, columns2);

    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

// Function to free memory allocated for a 2D array
void freeMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}


