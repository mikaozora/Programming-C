#include <stdio.h>

int main()
{
    int n = 9;
    int *ptr = &n;
    printf("value of n = %d\n", n);
    printf("value of ptr = %d\n", *ptr);
    *ptr = 15;
    printf("value of n = %d\n", n);
}