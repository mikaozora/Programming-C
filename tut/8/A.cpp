#include <stdio.h>

int main()
{
    int length;
    scanf("%d", &length);
    long long int arr[10001] = {};
    for (int i = 0; i < length; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        long long int res;
        scanf("%lld", &res);
        int count = 0;
        int max = 0;
        int maxCount = 0;
        for (int j = 0; j < length; j++)
        {
            int sum = 0;
            sum = arr[j];
            for (int k = j + 1; k < length; k++)
            {
                sum += arr[k];
                count++;
                printf("%d %d\n", count, maxCount);
                if (sum <= res && count > maxCount)
                {
                    max = sum;
                    maxCount = count;
                    // printf("%d\n", maxCount);
                }
            }
        }
    }
}