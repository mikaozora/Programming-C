#include <stdio.h>

int search(long long int *arr, long long int length, long long int req)
{
    long long int left = 0;
    long long int right = length - 1;
    long long int index = -1;
    while (left <= right)
    {
        long long int mid = (left + right) / 2;
        if (arr[mid] <= req)
        {
            left = mid + 1;
            index = mid;
        }else{
            right = mid - 1;
        }
    }
    return index;
}

int main()
{
    long long int length;
    scanf("%lld", &length);
    long long int sum = 0;
    long long int num = 0;
    long long int prefix[length + 1] = {};
    for (int i = 0; i < length; i++)
    {
        scanf("%lld", &num);
        sum += num;
        prefix[i] = sum;
    }
    // for(int i = 0; i < length; i++){
    //     printf("%lld ", prefix[i]);
    // }
    // printf("\n");
    int n;
    scanf("%d", &n);
    long long int req, index;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &req);
        index = search(prefix, length, req);
        printf("Case #%d: %lld\n",i,  (index == -1 ? -1 : index + 1));
    }
}