#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[] = "welcome to binus";
    char *str2 = (char*)"welcome to binus"; 
    // char const *str2 = "welcome to binus";
    char *temp;
    temp = str2;
    // printf("%c", *str);
    printf("%s\n", str);
    for(int i = 0; i < strlen(str); i++){
        printf("%c", *(temp + i));
    }
    // printf("%d",strcmp(str, *str));
    // char *name[] = {"Ali", "Ani", "Tono"};
    // char name[][10] = {"Ali", "Ani", "Tono"};
    // for(int i = 0; i < sizeof(name) / sizeof(name[0]; i++)){
    //     printf("%s ", name[i]);
    // }
}