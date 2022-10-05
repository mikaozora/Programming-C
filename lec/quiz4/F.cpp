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
        str2[i] = toupper(str[i]);
    }
    for (int i = 0; i < strlen(str2); i++)
    {
        ascii = str2[i];
        if (ascii == 73)
        {
            str2[i] -= 24;
        }
        else if (ascii == 82)
        {
            str2[i] -= 32;
        }
        else if (ascii == 69)
        {
            str2[i] -= 18;
        }else if(ascii == 65){
            str2[i] -= 13;
        }else if(ascii == 83){
            str2[i] -= 30;
        }else if(ascii == 71){
            str2[i] -= 17;
        }else if(ascii == 84){
            str2[i] -= 29;
        }else if(ascii == 66){
            str2[i] -= 10;
        }else if(ascii == 80){
            str2[i] -= 23;
        }else if(ascii == 79){
            str2[i] -= 31;
        }
    }

    printf("%s\n", str2);
}