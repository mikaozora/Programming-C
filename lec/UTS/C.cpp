#include <stdio.h>
#include <math.h>

int main(){
    int n;
    double per, month;
    long long int money;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &money);
        scanf("%lf", &per);
        scanf("%lf", &month);
        printf("Case #%d:\n", i);
        for(int j = 1; j <= month; j++){
            money += money * (per/100) / 12 * 0.8; 
            printf("%d %lld\n", j, money);
        }
    }
}