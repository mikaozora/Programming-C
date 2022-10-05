#include <stdio.h>

int main()
{
    int n, x, temp;
    int count;
    scanf("%d", &n);
    int arr[200000];

    for (int i = 0; i < n; i++)
    {
        for (int i = 0; i < 200000; i++)
        {
            arr[i] = 0;
        }
        scanf("%d", &x);
        for (int j = 0; j < x; j++)
        {
            scanf("%d", &temp);
            arr[temp] += 1;
        }
        count = arr[0];
        for (int j = 1; j < 200000; j++)
        {
            if (arr[j] > count)
            {
                count = arr[j];
            }
        }
        int y = 0;
        printf("Case #%d: %d\n", i + 1, count);
        for (int j = 0; j < 200000; j++)
        {
            if (arr[j] == count)
            {
                if (y != 0)
                {
                    printf(" ");
                    printf("%d", j);
                }else{
                    printf("%d", j);
                    y = 1;
                }
                
            }
        }
        printf("\n");
    }
    
}