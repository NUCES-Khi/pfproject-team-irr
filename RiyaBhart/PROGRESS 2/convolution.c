#include <stdio.h>

void fillMatrix(int matrix[][100], int n) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input. Please enter a valid integer.\n");
                return;
            }
        }
    }
}

void fillKernel(int kernel[][3]) {
    printf("Enter the 3x3 kernel matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (scanf("%d", &kernel[i][j]) != 1) {
                printf("Invalid input. Please enter a valid integer.\n");
                return;
            }
        }
    }
}

void convolution(int matrix[][100], int kernel[][3], int n) {
    if (n < 3) {
        printf("Matrix size should be at least 3x3 for convolution.\n");
        return;
    }

    int result[n - 2][n - 2];

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            result[i][j] = 0;

            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    
                    int matrixRow = i + x;
                    int matrixCol = j + y;

                    if (matrixRow >= 0 && matrixRow < n && matrixCol >= 0 && matrixCol < n) {
                        result[i][j] += matrix[matrixRow][matrixCol] * kernel[x][y];
                    }
                }
            }

            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the size of the square matrix: ");
    if (scanf("%d", &n) != 1 || n < 3) {
        printf("Invalid matrix size. Please enter a valid integer greater than or equal to 3.\n");
        return 1;
    }

    int matrix[100][100];
    fillMatrix(matrix, n);

    int kernel[3][3];
    fillKernel(kernel);

    printf("Convolution result:\n");
    convolution(matrix, kernel, n);

    return 0;
}
