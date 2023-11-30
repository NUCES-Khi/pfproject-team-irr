//the code needs to be called in functions and DMA will be implemented
#include<stdio.h>

int main() {

int m,n,p,q;
    int arr1[m][n],arr2[p][q],ans[m][q];

 //initializing all matrices
    printf("Enter the dimensions of the first matrix (mxn): ");
    scanf("%d %d", &m ,&n);
 
  printf("Enter the dimensions of the second matrix (pxq): ");
    scanf("%d %d", &p ,&q);
	
    //checking if the matrices can be multiplied.
	if(n != p){
        printf("The dimesions of the matrix are different and cannot be multiplied!\n");
        return 1;   
    }
    else 
    
    //input first matrix
	printf("enter elements of the first matrix:\n");
	 for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }

  //input second matrix 
    printf("enter elements of the second matrix:\n");
	 for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }

  //multiplying matrix
     for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < n; k++) {
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }


  //displaying answer
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
        return 0;
}
