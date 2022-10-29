#include <stdio.h>

int sumTree(int *arr, int lastIndex, int index, int count);

int main()
{
    int test;
    scanf("%d", &test);

    for (int i = 0; i < test; i++)
    {
        int length;
        scanf("%d", &length);
        int arr[length] = {};

        for (int j = 0; j < length; j++)
        {
            scanf("%d", &arr[j]);
        }

        printf("Case #%d:\n", i + 1);
        sumTree(arr, length, 1, arr[0]);
    }
}

int sumTree(int *arr, int lastIndex, int index, int count)
{
    if (index == lastIndex)
    {
        printf("%d\n", count);
        return 0;
    }

    else if ((index * 2) == lastIndex)
    {
        count += arr[index * 2 - 1];
        printf("%d\n", count);
        return 0;
    }
    else if ((index * 2) > lastIndex)
    {
        printf("%d\n", count);
        return 0;
    }

    else
    {
        sumTree(arr, lastIndex, (index * 2), count + arr[(index * 2) - 1]);
        sumTree(arr, lastIndex, ((index * 2) + 1), count + arr[index * 2]);
    }
}