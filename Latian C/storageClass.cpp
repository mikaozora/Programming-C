#include <stdio.h>
#include "test.cpp"

void display()
{
    static int a = 0; // static menyimpan nilai variabel hingga programnya selesai
                      // konsep hampir mirip dengan global variabel tetapi tidak bisa diakses semuanya
    a += 5;
    printf("%d ", a);
}

int main()
{
    register int c = 0;
    extern int x;
    display();
    display();
    printf("%d ", c);
    printf("1. %d\n", x);
    x = 100;
    printf("2. %d", x);
}