#include <stdio.h>
#include <string.h>

void fiboString(char a, char b, int n)
{
    if (n == 0)
    {
        printf("%c", a);
        return;
    }
    else if (n == 1)
    {
        printf("%c", b);
        return;
    }
    else
    {
        fiboString(a, b, n - 1);
        fiboString(a, b, n - 2);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    int n;
    char a, b;
    for (int i = 1; i <= t; i++)
    {
        scanf("%d %c %c", &n, &a, &b);
        getchar();
        printf("Case #%d: ", i);
        fiboString(a, b, n);
        printf("\n");
    }
}