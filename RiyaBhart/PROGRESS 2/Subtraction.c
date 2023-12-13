#include <stdio.h>
#include <stdlib.h>

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

    printf("SUBTRACTION OF THE TWO MATRICES\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d  ", arrfinal[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        free(arrfinal[i]);
    }
    free(arrfinal);
}

int main()
{
    int m, n;
    printf("Enter number of rows of First Matrix: ");
    scanf("%d", &m);
    printf("Enter number of columns of First Matrix: ");
    scanf("%d", &n);

    int **arr1 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        arr1[i] = (int *)malloc(n * sizeof(int));
    }

    int **arr2 = (int **)malloc(m * sizeof(int *));
    for (int i = 0; i < m; i++)
    {
        arr2[i] = (int *)malloc(n * sizeof(int));
    }

    printf("Enter values in first array:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter values in second array:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }

    printf("\nFirst array\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr1[i][j]);
        }
        printf("\n");
    }

    printf("\nSecond array\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", arr2[i][j]);
        }
        printf("\n");
    }

    matrixSubtraction(m, n, arr1, arr2);

    for (int i = 0; i < m; i++)
    {
        free(arr1[i]);
        free(arr2[i]);
    }
    free(arr1);
    free(arr2);

    return 0;
}
