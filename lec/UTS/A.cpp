#include <stdio.h>
#include <string.h>

int main()
{
    int n, k, test;
    scanf("%d", &test);

    for (int z = 0; z < test; z++)
    {
        scanf("%d", &n);
        scanf("%d", &k);
        int arr1[n][n] = {};
        int arr2[k][k] = {};
        int res[n - k + 1][n - k + 1] = {};
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr1[i][j]);
            }
        }
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &arr2[i][j]);
            }
        }
        for (int i = 0; i < n - k + 1; i++)
        {
            for (int j = 0; j < n - k + 1; j++)
            {
                for (int l = i; l < k + i; l++)
                {
                    for (int m = j; m < k + j; m++)
                    {
                        res[i][j] += arr1[l][m] * arr2[l - i][m - j];
                    }
                }
            }
        }
        for (int i = 0; i < n - k + 1; i++)
        {
            for (int j = 0; j < n - k + 1; j++)
            {
                printf("%d ", res[i][j]);
            }
            printf("\n");
        }
    }
}