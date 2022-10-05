#include <stdio.h>

int main(){
    int n, y, num;
    scanf("%d", &n);
    long long int arr[10000];
    long long int arr2[10000];
    for(int i = 1; i <= n; i++){
        scanf("%d", &y);
        int count = 0;
        for(int j = 0; j < y; j++){
            scanf("%lld", &arr[j]);
        }
        for(int j = 0; j < y; j++){
            scanf("%lld", &arr2[j]);
            if(arr2[j] > arr[j]){
                count++;
            }
        }
        printf("Case #%d: %d\n", i, count);
        
    }  
}