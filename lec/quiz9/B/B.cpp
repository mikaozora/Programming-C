#include <stdio.h>
#include <string.h>

int search(char arr[101][101], int length, char *str)
{
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (strcmp(arr[mid], str) == 0)
        {
            return mid;
        }
        else if (strcmp(arr[mid], str) > 0)
        {
            right = mid - 1;
        }
        else if (strcmp(arr[mid], str) < 0)
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    FILE *file;
    file = fopen("testdata.in", "r");
    int n;
    fscanf(file, "%d\n", &n);
    char first[101][101] = {};
    char last[101][101] = {};
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%[^#]#", first[i]);
        fscanf(file, "%[^\n]\n", last[i]);
    }
    int test;
    fscanf(file, "%d\n", &test);
    for (int i = 1; i <= test; i++)
    {
        char str[101] = {};
        fscanf(file, "%s\n", str);
        int index = search(first, n, str);
        printf("Case #%d: ", i);
        if (index != -1)
        {
            printf("%s\n", last[index]);
        }
        else
        {
            printf("N/A\n");
        }
    }
}