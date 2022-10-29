#include <stdio.h>
#include <string.h>
#include <ctype.h>

void isPalin(int i, int j, char *str)
{
    if (i >= j)
    {
        printf("YA");
        return;
    }
    else if (str[i] != str[j])
    {
        printf("BUKAN");
        return;
    }
    else
    {
        i++;
        j--;
        isPalin(i, j, str);
    }
    return;
}

int main()
{
    char str[110] = {};
    scanf("%s", str);
    int length = strlen(str) - 1;
    for(int i = 0; i <= length; i++){
        str[i] = tolower(str[i]);
    }
    isPalin(0, length, str);
}