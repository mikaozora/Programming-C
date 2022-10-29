#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <=n; i++){
        int days;
        long long int sum = 0;
        scanf("%d", &days);
        long long int arr[1001] = {};
        for(int y = 0; y < days; y++){
            scanf("%lld", &arr[y]);
            sum+= arr[y];
        }
        printf("Case #%d: %d\n", i, sum);
    }
}