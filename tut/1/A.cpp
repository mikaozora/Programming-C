#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d", &a);
    b = a + a;
    printf("%d plus %d is %d\n", a, a, b);
    c = b - 1;
    printf("minus one is %d\n", c);
}