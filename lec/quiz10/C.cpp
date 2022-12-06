#include <stdio.h>

int sum = 0;

int equation(int m, int n){
    if(m == 0){
        return 1;
    }else if(n == 0){
        return 1;
    }
    sum = equation(m-1, n-1) + equation(m-1, n) + equation(m, n-1);
    return sum;
}

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    equation(m, n);
    printf("%d\n", sum);
}