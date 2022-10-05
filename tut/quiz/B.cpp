#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int length, bibi, lili, p, q;
        scanf("%d", &length);
        int arr[10001] = {};
        for(int j = 0; j < length; j++){
            scanf("%d", &arr[j]);
        }
        scanf("%d %d", &p, &q);
        bibi = arr[p-1];
        lili = arr[q-1];
        printf("Case #%d : ", i);
        if(bibi > lili){
            printf("Bibi\n");
        }else if(lili > bibi){
            printf("Lili\n");
        }else{
            printf("Draw\n");
        }
    }
}