#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    file = fopen("testdata3.in", "r");
    int length;
    fscanf(file, "%d\n", &length);
    int page = 1;
    char str[11][100] = {};
    for (int i = 0; i < 10; i++)
    {
        bool check = true;
        int count = 0;
        fscanf(file, "%[^#]#", str[i]);
        fgetc(file);
        int length2 = strlen(str[i]);
        for (int j = 0; j < length2; j++)
        {
            if (str[i][j] == ' ')
            {
                count++;
            }
        }
        if (count != length)
        {
            printf("page %d: %d word(s)\n", i + 1, count);
            check = false;
        }
        if (!check)
        {
            break;
        }
        else
        {
            printf("The essay is correct\n");
            break;
        }
        fclose(file);
    }
    // while (!feof(file))
    // {
    //     char str[1000] ={};
    //     fscanf(file, "%[^#]", str);
    //     printf("%s", str);
    // }
}