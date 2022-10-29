#include <stdio.h>

int sum(int a){
    if(a < 1){
        return 0;
    }else{
        return a + sum(a-1);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    printf("sum: %d", sum(n));
}

