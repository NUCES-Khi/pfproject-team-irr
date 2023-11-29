#include<stdio.h>

int main() {
  //initializing all matrices
	int m,n,p,q;
    int arr1[m][n],arr2[p][q],ans[m][q];
	
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
if(n==q){ 
  //multiplying matrix
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i][j] = 0;
            for (int k = 0; k < n; k++) {
                ans[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}
  //displaying answer
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
