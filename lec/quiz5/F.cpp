#include <stdio.h>
#include <string.h>

int main()
{
    int n, len;
    long long int arr[100000];
    long long int arr2[100000];
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &len);
        for (int j = 0; j < len; j++)
        {
            scanf("%d", &arr[j]);
        }
        for (int j = 0; j < len; j++)
        {
            scanf("%d", &arr2[j]);
        }
        printf("Case #%d: ", i);
        int space = 0;
        for (int j = 0; j < len; j++)
        {
            printf("%s%d", (space == 0 ? "" : " "), arr[j] - arr2[j]);
            space++;
        }
        printf("\n");
    }
}