#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[5] = "abcd";
    char *ptr;
    ptr = string;
    // printf("%c\n", *(ptr + 1));
    // printf("%d", strlen(string));
    printf("%d\n", ptr + 1);
    for (int i = 0; i < strlen(string); i++)
    {
        printf("%c", *(ptr + i));
    }
    printf("\n==============\n");
    while (*ptr != '\0')
    {
        printf("%c", *ptr);
        ptr++;
    }
    printf("\n==============\n");
    char *str[4] = {"Jakarta", "Bogor", "Bandung", "Bekasi"};
    for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
    {
        for (int j = 0; j < strlen(str[i]); j++)
        {
            printf("%c", *(str[i] + j));
        }
        printf("\n");
    }
}