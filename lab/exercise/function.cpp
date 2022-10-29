#include <stdio.h>

void scanTwoNumbers(int *a, int *b){
    scanf("%d %d", a, b);
}

int main(){
    int first = 0, second = 0;
    printf("%d %d\n", first, second);
    scanTwoNumbers(&first, &second);
    printf("--------\n%d %d\n", first, second);
}