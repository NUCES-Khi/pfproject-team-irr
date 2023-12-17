#include <stdio.h>

void fillMatrix(int matrix[][100], int n) {
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void fillKernel(int kernel[][100], int n) {
    printf("Enter the kernel matrix:\n");
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            scanf("%d", &kernel[i][j]);
            if (kernel[i][j] != 0 && kernel[i][j] != 1 && kernel[i][j] != -1) {
                printf("Invalid input. Please enter a valid integer (0, 1, or -1).\n");
                return;
            }
        }
    }
}

void convolution(int matrix[][100], int kernel[][100], int n) {
    if (n < 3) {
        printf("Matrix size should be at least 3x3 for convolution.\n");
        return;
    }

    int result[100][100];

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

    int kernel[100][100];
    fillKernel(kernel, n);

    printf("Convolution result:\n");
    convolution(matrix, kernel, n);

    return 0;
}
