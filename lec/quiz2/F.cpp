#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int x[n];
    for (int a = 0; a < n; a++)
    {
        scanf("%d", &x[a]);
    }
    for (int b = 0; b < n; b++)
    {
        printf("Case #%d:\n", b + 1);
        for (int c = 0; c < x[b]; c++)
        {
            for (int d = c; d < x[b] - 1; d++)
            {
                printf(" ");
            }
            if (x[b] % 2 == 0)
            {
                for (int e = 0; e <= c; e++)
                {
                    if (e % 2 == 0)
                    {
                        printf("#");
                    }
                    else
                    {
                        printf("*");
                    }
                }
            }else{
                for (int e = 1; e <= c + 1; e++)
                {
                    if (e % 2 == 0)
                    {
                        printf("#");
                    }
                    else
                    {
                        printf("*");
                    }
                }
            }

            printf("\n");
        }
    }
}