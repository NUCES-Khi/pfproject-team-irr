#include <stdio.h>

int main() {
    int n;
    printf("Enter size of your array: ");
    scanf("%d", &n);
    int arr[n][n];
    printf("Enter values in array: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int brr[n-2][n-2];
    int a = 0, b = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            int sum = 0;
            for (int l = 0; l < 3; l++) {
                for (int m = 0; m < 3; m++) {
                    sum += arr[i+l][j+m];
                }
            }
            brr[a][b] = sum;
            b++;
        }
        a++;
        b = 0;
    }

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < n - 2; j++) {
            printf("%d\t", brr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
