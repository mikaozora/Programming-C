#include <stdio.h>

int main()
{
    FILE *file = fopen("testdata.in", "r");
    int length;
    fscanf(file, "%d\n", &length);

    char word[1000];
    int page = 1, count = 0, check = 1;

    while (fscanf(file, "%s", word) != EOF)
    {
        printf("%s", word);
        if (word[0] == '#')
        {
            if (count < length)
            {
                check = 0;
                printf("page %d: %d word(s)\n", page, count);
            }
            count = 0;
            page++;
        }
        else
        {
            count++;
        }
    }

    if (check == 1)
    {
        printf("The essay is correct\n");
    }

    fclose(file);
    return 0;
}