#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    long long int rooms;
    int arr[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int same = 0;
        scanf("%lld", &rooms);
        for (int y = 0; y < count; y++)
        {
            if (rooms == arr[y])
            {
                same = 1;
            }
        }
        if (!same)
        {
            arr[count] = rooms;
            count++;
        }
    }
    printf("%d\n", count);
}