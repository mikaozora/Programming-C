#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int count = 0;
    long long int kamar;
    long long int arr[n + 1];
    for (int i = 0; i < n; i++)
    {
        int res = 1;
        scanf("%lld", &kamar);
        for (int j = 0; j < count; j++)
        {
            if (kamar == arr[j])
                res = 0;
        }
        if (res == 1)
        {
            arr[count] = kamar;
            count++;
        }
    }
    printf("%d\n", count);
    return 0;
}