#include <stdio.h>

int fibo(int a, int b, int n)
{
    if (n == 0)
    {
        return a;
    }
    else if (n == 1)
    {
        return b;
    }
    else
    {
        printf("%d+%d", fibo(a, b, n - 1), fibo(a, b, n - 2));
        printf(" fibo(%d, %d, %d) -- fibo(%d, %d, %d)\n", a, b, n-1, a, b, n-2);
        return fibo(a, b, n - 1) + fibo(a, b, n - 2);
    }
}

int main()
{
    int a, b, n;
    scanf("%d %d", &a, &b);
    scanf("%d", &n);
    printf("%d", fibo(a, b, n));
}