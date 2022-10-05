#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[1000];
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        int length = strlen(str);
        printf("Case #%d: ", i);
        for (int j = 0; j < length / 2; j++)
        {
            printf("%c", str[j]);
        }
        for (int j = (length % 2 == 0 ? length/2-1 : length/2); j >= 0; j--)
        {
            printf("%c", str[j]);
        }
        printf("\n");
    }
}