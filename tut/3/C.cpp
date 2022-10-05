#include <stdio.h>

int main(){
    int n, y;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &y);
        long long int arr[y][y];
        long long int sum[y];
        for(int j = 0; j < y; j++){
            sum[j] = 0;
        }
        for(int j = 0; j < y; j++){
            for(int k = 0; k < y; k++){
                scanf("%lld", &arr[j][k]);
            }
        }
        for(int j = 0; j < y; j++){
            for(int k = 0; k < y; k++){
                sum[j] += arr[k][j];
            }
        }

        printf("Case #%d: ", i);
        int space = 0;
        for(int j = 0; j < y; j++){
            printf("%s%d", (space == 0 ? "" : " ") ,sum[j]);
            space++;
        }
        printf("\n");
    }
}