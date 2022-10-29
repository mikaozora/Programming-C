#include <stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    int n;
    long long int x, y;
    for (int i = 1; i <= t; i++)
    {
        int res[25] = {};
        scanf("%d %lld %lld", &n, &x, &y);
        res[0] = x;
        res[1] = y;
        for (int j = 2; j < 25; j++)
        {
            res[j] = res[j - 1] - res[j - 2];
        }
        printf("Case #%d: %d\n", i, res[n]);
    }
}