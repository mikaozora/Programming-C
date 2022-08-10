#include <stdio.h>
#include <string.h>

void stringFunc(char name[])
{
    printf("nama: %s", name);
}

// string basic
// int main()
// {
//     char name[100];
//     printf("masukkan nama: ");
//     fgets(name, sizeof(name), stdin);
//     stringFunc(name);
//     char *ptr;
//     ptr = name;
//     printf("%c", *(ptr + 1));
// }

// string manipulation
int main()
{
    char textA[100], textB[100];
    char textC[100];
    printf("masukkan text A: ");
    fgets(textA, sizeof(textA), stdin);
    printf("masukkan text B: ");
    fgets(textB, sizeof(textB), stdin); // fgets use \n in last characters. the length of string is character + \n
    printf("masukkan text C: ");
    scanf("%[^\n]", textC); getchar(); // scanf is the best solution for me
    int lengthA = 0, lengthB = 0;
    lengthA = strlen(textA); // get length of string
    lengthB = strlen(textB);
    printf("text A: %s", textA);
    printf("text B: %s", textB);
    printf("text B after strcpy(): %s", strcpy(textB, textA));
    strcat(textC, textA); // join two string
    printf("text C join text A: %s\n", textC);
    printf("length A: %zu\n", lengthA);
    printf("length B: %d\n", lengthB);
    printf("length C: %d\n", strlen(textC));
    printf("text A compares to text C: %d", strcmp(textA, textC)); //compares two string. if a > b return >0, if a < b return <0, if a == b return 0
}