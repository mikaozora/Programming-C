#include <stdio.h>
#include <string.h>
char str[10000000] = {};
// But, if you declare it globally, then it's size can be increased 
// nearly to the remaining memory left in your PC
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {

        scanf("%s", str);
        int length = strlen(str);
        int odd = 0, even = 0, result;
        for (int j = 0; j < length; j++)
        {
            if (j % 2 == 0)
            {
                even += str[j] - '0';
            }
            else
            {
                odd += str[j] - '0';
            }
        }
        result = (odd - even) % 11;
        printf("Case #%d: ", i);
        if (result == 0)
        {
            printf("Yeah\n");
        }
        else
        {
            printf("Nah\n");
        }
    }
}