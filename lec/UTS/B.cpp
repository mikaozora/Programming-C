#include <stdio.h>
#include <string.h>

int main()
{
    char str[1001] = {};
    scanf("%s", str);
    int length = strlen(str);
    int count = 0;
    int index[150] = {};
    char palin[1001][1001] = {};
    int palinIndex = 0;
    for (int i = 0; i < length; i++)
    {
        index[str[i]] = 1;
    }
    for (int i = 0; i < 128; i++)
    {
        if (index[i] == 1)
        {
            count++;
        }
    }

    for (int j = 1; j < length; j++)
    {
        for (int k = 0; k < length - j; k++)
        {
            int res = 1;
            int same = 0;
            char temp[1001] = {};
            for (int m = k; m < k + j + 1; m++)
            {
                temp[m - k] = str[m];
            }
            int lenght2 = strlen(temp);
            for (int m = 0; m < lenght2 / 2; m++)
            {
                if (temp[m] != temp[lenght2 - m - 1])
                {
                    res = 0;
                }
            }
            if (res)
            {
                
                for (int z = 0; z < palinIndex; z++)
                {
                    if (strcmp(palin[z], temp) == 0)
                    {
                        same = 1;
                        break;
                    }
                }
                if (!same)
                {
                    strcpy(palin[palinIndex], temp);
                    count++;
                }
                palinIndex++;
                same = 0;
            }
        }
    }
    // for (int i = 0; i < palinIndex; i++)
    // {
    //     printf("%s ", palin[i]);
    // }
    printf("%d", count);
}