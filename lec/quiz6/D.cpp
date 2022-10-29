#include <stdio.h>

int main(){
    long long int n, a, b, temp;
    scanf("%lld", &n);
    temp = n - 1;
    a = temp / 2;
    b = a + 1;
    printf("%lld = %lld + %lld\n", n, a, b);
}