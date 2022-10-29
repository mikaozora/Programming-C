#include <stdio.h>
#include <math.h>

int komposisi(int a, int b, int k, int x)
{
    int result;
    if (k < 1)
    {
        return x;
    }
    else
    {
        x = komposisi(a, b, k - 1, x);
        result = a * x + b;
        return abs(result);
    }
}

int main()
{
    int a, b, k, x;
    scanf("%d %d %d %d", &a, &b, &k, &x);
    printf("%d", komposisi(a, b, k, x));
}