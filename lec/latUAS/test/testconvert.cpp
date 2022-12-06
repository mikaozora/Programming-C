#include <stdio.h>
#include <string.h>

int main()
{
    char horse1[100] = {};
    char horse2[100] = {};
    scanf("%s", horse1);
    getchar();
    scanf("%s", horse2);
    getchar();
    int x1, y1, x2, y2;

    x1 = horse1[0] - 65;
    y1 = horse1[1] - 49;
    printf("%d %d", x1, y1);
}