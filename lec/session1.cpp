#include <stdio.h>
#define AGE 10
#define phi 3.14

int globe = 50;

int main()
{
    printf("hello world\t");
    printf("hello world\n");
    printf("hello world\n");
    printf("---------------------------\n");

    int x;
    x = 10;
    printf("x : %d\n", x);
    x = 20;
    printf("new x : %d\n", x);
    printf("---------------------------\n");
    float y = 25;
    printf("y : %f\n", y);
    printf("y : %.2f\n", y);
    printf("---------------------------\n");

    int a;
    printf("masukkan nilai a : ");
    scanf("%d", &a);
    printf("a : %d\n", a);

    int globe = 60;
    printf("a + y : %f\n", a + y);
    printf("phi : %.2f\n", phi);
    printf("globe : %d\n", globe);
    printf("---------------------------\n");

    char name[20] = "mika ozora";
    printf("%s\n", name);
    printf("%15s\n", name);
    printf("%.2s\n", name);

    char ibu[20];
    printf("masukkan nama ibu : ");
    scanf("%s", ibu);
    getchar();
    printf("nama ibu : %s\n", ibu);
    printf("---------------------------\n");

    int k, l, m, n, o;
    k = scanf("%d %d %d %d", &l, &m, &n, &o);
    printf("%d\n", k);
    printf("---------------------------\n");

    char ss1[40];
    char ss2[40];
    k = scanf("%s %s\n", ss1, ss2);
    printf("%d\n", k);
    printf("%s\n", ss1);
    printf("%s\n", ss2);
}