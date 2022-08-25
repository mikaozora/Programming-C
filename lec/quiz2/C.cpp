#include <stdio.h>

int main()
{
    int a, b, n1, n2;
    scanf("%d", &a);
    int days[a];
    for (int i = 0; i < a; i++)
    {
        scanf("%d", &days[i]);
    }
    scanf("%d", &b);
    int result[b];
    for (int z = 0; z < b; z++)
    {
        result[z] = 0;
    }
    int x = 0;
    for (int j = 0; j < b; j++)
    {
        scanf("%d %d", &n1, &n2);  
        for (int y = n1; y <= n2; y++)
        {
            result[x] += days[y - 1];
        }
        x = x+1;
    }

    for (int k = 1; k <= b; k++)
    {
        printf("Case #%d: %d\n", k, result[k - 1]);
    }
}