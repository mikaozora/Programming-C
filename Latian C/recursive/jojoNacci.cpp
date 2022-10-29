#include <stdio.h>

int jojoNanci(int a, int b, int n){
    if(n == 0){
        return a;
    }else if(n == 1){
        return b;
    }else{
        return jojoNanci(a, b, n-1) - jojoNanci(a,b, n- 2);
    }
}

int main(){
    int n, a, b, c;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d", &c, &a, &b);
        printf("Case #%d: %d", i, jojoNanci(a, b, c));
        printf("\n");
    }
}