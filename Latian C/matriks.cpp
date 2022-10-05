#include <stdio.h>
#include <string.h>

int main()
{
    int a, b, c, d;
    do
    {
        // printf("matriks A [a x b]: " );
        scanf("%d %d", &a, &b);
        // printf("matriks B [a x b]: " );
        scanf("%d %d", &c, &d);
    } while (b != c);
    int sum = 0;
    int matA[a][b] = {};
    int matB[c][d] = {};
    int result[a][d] = {};
    int rowA = sizeof(matA) / sizeof(matA[0]);
    int columnA = sizeof(matA[0]) / sizeof(int);
    int rowB = sizeof(matB) / sizeof(matB[0]);
    int columnB = sizeof(matB[0]) / sizeof(int);
    int lengthA = (sizeof(matA) / sizeof(matA[0])) * (sizeof(matA[0]) / sizeof(int));
    int lengthB = (sizeof(matB) / sizeof(matB[0])) * (sizeof(matB[0]) / sizeof(int));
    for (int i = 0; i < rowA; i++)
    {
        for (int j = 0; j < columnA; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }
    for (int i = 0; i < rowB; i++)
    {
        for (int j = 0; j < columnB; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }
    // printf("%d\n", matA[1][0]);
    // printf("%d\n", rowA);
    // printf("---------------\n");
    for (int k = 0; k < rowA; k++)
    {
        for (int i = 0; i < columnB; i++)
        {
            for (int j = 0; j < columnA; j++)
            {
                // printf("%d*%d ", matA[i][j], matB[j][i]);
                sum += matA[k][j] * matB[j][i];
                // printf("= %d + ", sum);
                result[k][i] = sum;
            }
            sum = 0;
            // printf("\n");
        }
        // printf("---------------\n");
    }
    for(int i = 0; i < rowA; i++){
        for(int j = 0; j < columnB; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}