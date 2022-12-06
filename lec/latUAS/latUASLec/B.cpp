#include <stdio.h>

int main()
{
    int x;
    scanf("%d", &x);
    int length;
    scanf("%d", &length);
    int arr[100] = {};
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    int a, b;
    int count = 0;
    for (int i = 0; i < length/2; i++)
    {
        a = arr[i];
        for (int j = 0; j < length; j++)
        {
            b = arr[j];
            if(a + b == x){
                printf("%d %d\n", a, b);
            }
        }
    }
}