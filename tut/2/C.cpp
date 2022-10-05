#include <stdio.h>

int main()
{
    int n, req;
    scanf("%d %d", &n, &req);

    for (int j = 0; j < n; j++)
    {
        for (int k = 0; k < n; k++)
        {
            printf("#");
        }
        printf("\n");
    }
    printf("\n");

    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (j % req == 0)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");

    for (int j = 1; j <= n; j++)
    {
        for (int k = 1; k <= n; k++)
        {
            if (k % req == 0)
            {
                printf("#");
            }
            else
            {
                printf(".");
            }
        }
        printf("\n");
    }
}