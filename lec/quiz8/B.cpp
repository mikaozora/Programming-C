#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long int result = pow(2, n) - 1;
    printf("%lld\n", result);
}