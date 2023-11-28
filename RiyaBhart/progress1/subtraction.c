#include <stdio.h>
int main(){
    int m,n,p,q;
    printf("Enter number of rows of First Matrix: ");
    scanf("%d",&m);
    printf("Enter number of columns of First Matrix: ");
    scanf("%d",&n);
    int arr1[m][n];
     printf("Enter number of rows of Second matrix: ");
    scanf("%d",&p);
    printf("Enter number of columns of Second Matrix: ");
    scanf("%d",&q);
    int arr2[p][q];
    if(m==p && n==q){
    printf("enter values in first array: \n");
    for(int i=0;i<m;i++){//taking inputs of first matrix
        for(int j=0;j<n;j++){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("\n");
    printf("enter values in second array: \n");
    for(int i=0;i<p;i++){//taking inputs of seconding matrix
        for(int j=0;j<q;j++){
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("\nFirst array\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arr1[i][j]);
        }
        printf("\n");
    }
    printf("\nSecond array\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            printf("%d\t",arr2[i][j]);
        }
        printf("\n");
    }
    int arrfinal[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            arrfinal[i][j]=arr1[i][j]-arr2[i][j];
        }
    }
    printf("SUBTRACTION OF THE TWO MATRICES\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d\t",arrfinal[i][j]);
        }
        printf("\n");
    }
    }
    
    else
    {
        printf("The two matrices are not of the same size.");
    }
    
    return 0;
}
