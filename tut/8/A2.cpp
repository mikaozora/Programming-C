#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int q;

    long long arr[5050];
    long long comp[5050] = {};
    int n;
    long long m;
    long long x;
    scanf("%d", &n);
    comp[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        scanf("%lld", &x);
        comp[j] = x + comp[j - 1];
    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        scanf("%lld", &m);
        int maks = -1;
        for (int j = 0; j < n; j++)
        {
            for (int k = n; k >= j + 1; k--)
            {
                printf("%lld %lld %lld\n", comp[k], comp[j], m);
                if (comp[k] - comp[j] <= m)
                {
                    printf("%d----%d\n", k, j);
                    if (k - j > maks)
                    {
                        maks = k - j;
                        break;
                    }
                    if (k - j < maks)
                        break;
                }
            }
        }
        printf("Case #%d: %d\n", i + 1, maks);
    }
}