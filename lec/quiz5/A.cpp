#include <stdio.h>
#include <string.h>

int main()
{
    // char str[100] = "Hello world";
    // char *token = strtok(str, " ");
    // char temp[1000];
    // strcpy(temp, strcat(token, "szs"));
    // printf("%s\n", temp);
    // printf("-----------\n");
    // token = strtok(NULL, " ");
    // printf("%s\n", token);
    char str[30];
    char str1[30];
    char str2[30];
    for(int i = 0; i < 2; i++){
        scanf("%s %s %s", str, str1, str2);
        printf("%sszs %sszs %sszs\n", str, str1, str2);
    }
}