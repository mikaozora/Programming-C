#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    file = fopen("testdata.in", "r");
    int n, ascii;
    fscanf(file, "%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        char str[1001];
        fscanf(file, "%d\n", &ascii);
        fscanf(file, "%[^\n]\n", str);
        int length = strlen(str);
        for (int y = 0; y < length; y++)
        {
            if (str[y] == '0')
            {
                str[y] = 'O';
            }
            else if (str[y] == '1')
            {
                str[y] = 'I';
            }
            else if (str[y] == '3')
            {
                str[y] = 'E';
            }
            else if (str[y] == '4')
            {
                str[y] = 'A';
            }
            else if (str[y] == '5')
            {
                str[y] = 'S';
            }
            else if (str[y] == '6')
            {
                str[y] = 'G';
            }
            else if (str[y] == '7')
            {
                str[y] = 'T';
            }
            else if (str[y] == '8')
            {
                str[y] = 'B';
            }
            else if (str[y] == ' ')
            {
                continue;
            }
            if ((str[y] - ascii) < 65)
            {
                str[y] = str[y] + (26 - ascii);
            }
            else
            {
                str[y] = str[y] - ascii;
            }
        }
        printf("Case #%d: %s\n", i, str);
    }
    fclose(file);
}