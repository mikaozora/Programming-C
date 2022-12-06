#include <stdio.h>

int search(long long int *arr, long long int length, long long int req)
{
    long long int left = 0;
    long long int right = length - 1;
    while (left <= right)
    {
        long long int mid = (left + right) / 2;
        // printf("mid : %d\n", mid);
        if (arr[mid] == req)
        {
            return mid;
        }
        else if (arr[mid] > req)
        {
            if (right > 0 && right < length)
            {
                right = mid - 1;
            }
            if (right == 0)
            {
                if (arr[right] > req)
                {
                    return -1;
                }
            }
            // printf("right : %d\n", right);
            if (arr[right] < req)
            {
                return right;
            }
            else if (arr[right] != req)
            {
                right = mid + 1;
            }
        }
        else
        {
            if (left > 0 && left < length)
            {
                left = mid + 1;
            }
            if (left == length - 1)
            {
                if (arr[length - 1] < req)
                {
                    return length - 1;
                }
            }
            // printf("left : %d\n", left);
            if (arr[left] > req)
            {
                return left - 1;
            }
            else if (arr[left] != req)
            {
                left = mid + 1;
            }
        }
    }
    return -5;
}

int main()
{
    long long int length;
    scanf("%lld", &length);
    long long int num;
    long long int prefix[100000] = {};
    long long int sum = 0;
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
        printf("Case #%d: %lld\n", i, (index == -1 ? -1 : index + 1));
    }
}