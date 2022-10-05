#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long int num, res;

    for (int i = 1; i <= n; i++)
    {
        long long int multiply = 1;
        int result[10];
        int index = 0;
        scanf("%lld", &num);
        printf("Case #%d: ", i);
        if (num == 0)
        {
            printf("0");
        }
        else
        {
            while (num)
            {
                res = num % 10;
                res *= multiply;
                multiply *= 10;
                num /= 10;
                result[index] = res;
                index++;
            }
        }
        for (int j = index - 1; j >= 0; j--)
        {
            if (result[j] == 0)
            {
                continue;
            }
            printf("%d ", result[j]);
        }
        printf("\n");
    }
}