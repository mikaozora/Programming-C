#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    // char str[100001];
    // int ascii[150];

    for (int i = 1; i <= n; i++)
    {
        char str[100001] = {};
        int ascii[150] = {};
        // for (int i = 0; i < 150; i++)
        // {
        //     ascii[i] = 0;
        // }
        int count = 0;
        scanf("%s", str);
        for (int j = 0; j < strlen(str); j++)
        {
            if (ascii[str[j]] == 0)
            {
                ascii[str[j]] = 1;
            }
        }
        for (int j = 0; j < 150; j++)
        {
            if (ascii[j] > 0)
            {
                count++;
            }
        }
        printf("Case #%d: %s\n", i, (count % 2 == 0 ? "Breakable" : "Unbreakable"));
    }
}