#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // srand(time(NULL));
    // printf("%d\n", rand());
    // printf("%d", rand()%10+1);
    int id;
    scanf("%d", &id);
    int res = 0;
    char num[1] = {};
    // sprintf(num, "%d", id%10);
    while (id)
    {
        sprintf(num, "%d", id%10);
        id /= 10;
        if (isdigit(num[0]) == 1)
        {
            res = 1;
        }
        else
        {
            res = 0;
        }
    }
    printf("%s-\n", num);
    printf("%d", res);
    // char num = '1';
    // printf("%d", isdigit(num));
}