#include <stdio.h>

int main(){
    long long int n, x; 
    long long int result, count = 0;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        scanf("%lld", &x);
        long long int arr[2000];
        result = 0;
        count = 0;
        for(int j = 0; j < x; j++){
            scanf("%lld", &arr[j]);
            result += arr[j];
        }
        for(int j = 0; j < x; j++){
            if(arr[j] > result){
                count++;
            }
        }
        printf("Case #%d: %lld\n%lld\n", i+1, result, count);
    }
}