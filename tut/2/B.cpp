#include <stdio.h>

int main()
{
    int n, items, num;
    long long int sum;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        scanf("%d", &items);
        for (int j = 0; j < items; j++)
        {
            scanf("%d", &num);
            sum += num;
        }
        printf("Case #%d: %lld\n", i + 1, sum);
    }
}