#include <stdio.h>

int main(){
    int n, x, row, temp;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    for(int i = 0; i < x; i++){
        scanf("%d %d", &row, &temp);
        arr[row-1] = temp;
        printf("Case #%d: ", i+1);
        for(int j = 0; j < n; j++){
            printf("%d", arr[j]);
            if(j < n-1){
                printf(" ");
            }
        }
        printf("\n");
    }
}