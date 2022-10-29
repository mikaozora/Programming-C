#include <stdio.h>

int sumTree(int *arr, int sum, int index, int lastIndex)
{
    if (index == lastIndex)
    {
        printf("%d\n", sum);
        return 0;
    }
    else if (index * 2 == lastIndex)
    {
        sum += arr[index * 2 - 1];
        printf("%d\n", sum);
        return 0;
    }
    else if (index * 2 > lastIndex)
    {
        printf("%d\n", sum);
        return 0;
    }
    else
    {
        sumTree(arr, sum + arr[index * 2] - 1, index * 2, lastIndex);
        sumTree(arr, sum + arr[index * 2], index * 2 + 1, lastIndex);
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        int length;
        scanf("%d", &length);
        int arr[length] = {};
        for (int j = 0; j < length; j++)
        {
            scanf("%d", &arr[j]);
        }
        printf("Case #%d:\n", i);
        sumTree(arr, arr[0], 1, length);
    }
}