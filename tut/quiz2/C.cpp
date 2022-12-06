#include <stdio.h>

int bubbleSort(int arr[], int length){
    int count = 0;
    for(int i = 0; i < length-1; i++){
        for(int j = 0; j < length - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    scanf("%d", &n);
    int length, mnt;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &length, &mnt);
        int arr[length + 1] = {};
        for (int j = 0; j < length; j++)
        {
            scanf("%d", &arr[j]);
        }
        int count = bubbleSort(arr, length);
        printf("Case #%d: %d\n", i, count*mnt);
    }
}