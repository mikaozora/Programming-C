#include <stdio.h>

int main(){
    int n; 
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        long long int a, b, sum;
        long long int result = 0, multiply = 1;
        scanf("%lld %lld", &a, &b);
        while(a ||b){
            sum = ((a%10) + (b%10)) % 10;
            result += sum * multiply;
            multiply *= 10;
            a /= 10;
            b /= 10;
        }
        printf("Case #%d: %lld\n", i, result);
    }
}