#include <stdio.h>

int main()
{
    int n, x;
    scanf("%d", &n);
    int arr[n];
    int arrTemp[n];
    for (int j = 0; j < n; j++)
    {
        scanf("%d", &arrTemp[j]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[arrTemp[i]]);
    }
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
        if(i < n - 1){
            printf(" ");
        }
    }
    printf("\n");
}