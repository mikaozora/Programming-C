#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char str[1001];
    char temp[1001];
    for (int i = 1; i <= n; i++)
    {

        scanf("%s", str);
        int length = strlen(str);
        for (int j = 0; j < length; j++)
        {
            if (str[j] >= 'A' && str[j] <= 'Z')
            {
                str[j] = tolower(str[j]);
            }
            else
            {
                str[j] = toupper(str[j]);
            }
        }
        for (int j = 0; j < length / 2; j++)
        {
            temp[j] = str[j];
            str[j] = str[length - j - 1];
            str[length - j - 1] = temp[j];
        }
        printf("Case #%d: %s\n", i, str);
    }
}