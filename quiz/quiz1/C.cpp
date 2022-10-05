#include <stdio.h>

int main()
{
    long long int n;
    scanf("%lld", &n);
    long long int arr[n];
    long long int sum = 0, min = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if(arr[i] % 2 != 0){
            min = arr[i];
        }
        sum += arr[i];
    }
    for(int i = 0; i < n; i++){
        if(arr[i] % 2 != 0){
            if(min > arr[i]){
                min = arr[i];
            }
        }
    }
    // printf("%lld\n", min);
    if(sum % 2 == 0){
        printf("%lld\n", sum);
    }else{
        printf("%lld\n", sum-min);
    }
}