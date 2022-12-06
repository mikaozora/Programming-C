#include <stdio.h>

int func(long long int arr[], int x, int k, long long int n){
    if(k > n || k < 0){
        return 0;
    }else if(x >= n){
        return 0;
    }
    long long int sum = 0;
    sum = arr[x] * k;
    // printf("%lld\n", sum);
    return sum + func(arr, x+1, k-1, n);
}

int main(){
    long long int length;
    scanf("%lld", &length);
    long long int arr[length + 1] = {};
    for(int i = 0; i < length; i++){
        scanf("%lld", &arr[i]);
    }
    long long int m;
    scanf("%lld", &m);
    long long int max = 0;
    for(int x = 0; x < length; x++){
        for(int k = length; k >= 0; k--){
            long long int temp = func(arr, x, k, length);
            if(temp <= m){
                if(temp > max){
                    max = temp;
                }              
            }
        }
    }
    printf("%lld\n", max);
}