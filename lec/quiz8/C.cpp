#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n; i++){
        long long int dec;
        int index = 0;
        int bin[100] = {};
        scanf("%lld", &dec);
        while(dec){
            bin[index] = dec % 2;
            index++;
            dec /= 2;
        }
        printf("Case #%d: ", i);
        for(int y = index-1; y >= 0; y--){
            printf("%d", bin[y]);
        }
        printf("\n");
    }
}