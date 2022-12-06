#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    int length = pow(2, n) - 1;
    int i = 0;
    while (length)
    {
        int space = pow(2, i) - 1;
        for (int j = 0; j < length; j++)
        {
            if (i > 0)
            {
                for (int j = 0; j < space; j++)
                {
                    printf(" ");
                }
                printf("*");
            }
            else
            {
                printf("*");
            }
        }
        i++;
        length /= 2;
        printf("\n");
    }
}