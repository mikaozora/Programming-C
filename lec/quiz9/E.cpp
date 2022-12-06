#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
    {
        long long int length;
        long long int req;
        scanf("%lld %lld", &length, &req);
        // long long int arr[length + 1] = {};
        long long int input;
        long long int prefix[length + 5] = {};
        prefix[0] = 0;
        for (int j = 1; j <= length; j++)
        {
            // scanf("%lld", &arr[j - 1]);
            scanf("%lld", &input);
            prefix[j] = prefix[j - 1] + input;
        }
        long long int max = -1;
        for (int j = 0; j < length; j++)
        {
            for (int k = length; k >= j + 1; k--)
            {
                // printf("%lld %lld %lld\n", prefix[k], prefix[j], req);
                if (prefix[k] - prefix[j] <= req){
                    // printf("--%d %d--\n", k, j);
                    if(k - j > max){
                        max = k - j;
                        break;
                    }else{
                        break;
                    }
                }
            }
        }
        printf("Case #%d: %lld\n", i, max);
    }
}