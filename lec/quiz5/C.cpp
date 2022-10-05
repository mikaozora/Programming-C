#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[10000];
    char str2[10000];
    int ascii;
    scanf("%[^\n]", str);
    for (int i = 0; i < strlen(str); i++)
    {
        str2[i] = tolower(str[i]);
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        ascii = str2[i];
        if (ascii == 49)
        {
            str2[i] += 56;
        }
        else if (ascii == 50)
        {
            str2[i] += 64;
        }
        else if (ascii == 51)
        {
            str2[i] += 50;
        }else if(ascii == 52){
            str2[i] += 45;
        }else if(ascii == 53){
            str2[i] += 62;
        }else if(ascii == 54){
            str2[i] += 49;
        }else if(ascii == 55){
            str2[i] += 61;
        }else if(ascii == 56){
            str2[i] += 42;
        }else if(ascii == 57){
            str2[i] += 55;
        }else if(ascii == 48){
            str2[i] += 63;
        }
    }

    printf("%s\n", str2);
}