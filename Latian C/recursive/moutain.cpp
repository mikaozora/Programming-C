#include <stdio.h>

void mount(int n){
    if(n == 1){
        printf("*\n");
    }else{
        mount(n-1);
        for(int i = 0; i < n; i++){
            printf("*");
        }
        printf("\n");
        mount(n-1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    mount(n);
}