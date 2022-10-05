#include <stdio.h>

int main(){
    int n, left, right;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &left, &right);
        printf("Case #%d: ", i +1);
        if(left > right){
            printf("Go-Jo\n");
        }else{
            printf("Bi-Pay\n");
        }
    }
}