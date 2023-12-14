/*
The code below is used for transposing a matrix using dynamically allocated memory.
*/

#include <stdio.h>
#include<stdlib.h>


//function to take input and display the matrix
void InputM(int m, int n, int **matrix) {
  
    printf("Enter values of the Matrix you want to Transpose: \n");
    for(int i=0;i<m;i++){//taking inputs of  matrix
        for(int j=0;j<n;j++){
            scanf("%d",&matrix[i][j]);
        }
    }

//printing the user-input matrix
    printf("The Matrix is:");
    printf("\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }

}

//function for transposing a matrix
void TransposeM(int m, int n, int **matrix){

 printf("Transpose of the matrix is:\n");
     for(int i=0; i<n; i++) {
         for(int j=0; j<m; j++){
             printf("%d\t", matrix[j][i]);
         }
         printf("\n");
     }    
}

//calling all functios in main 
int main() {
int m,n;

    printf("Enter number of rows of Matrix: ");
    scanf("%d",&m);
    printf("Enter number of columns of Matrix: ");
    scanf("%d",&n);

// Dynamically allocate memory for the matrix
    int **matrix = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }
  
        InputM(m,n,matrix);
        TransposeM(m,n,matrix);

    // Free dynamically allocated memory
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;

}
