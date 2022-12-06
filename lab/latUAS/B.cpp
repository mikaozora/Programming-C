#include <stdio.h>
#include <string.h>

void swap(long long int* a, long long int* b){
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(long long int arr[], int low, int high){
    long long int pivot = arr[high];
    int i = low-1;
    int j = low;
    while(j <= high){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void sort(long long int arr[], int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        sort(arr, low, part-1);
        sort(arr, part+1, high);
    }
}

int main()
{
    int test;
    scanf("%d", &test);
    for (int j = 1; j <= test; j++)
    {
        int n;
        scanf("%d", &n);
        int length = 4 * n - 1;
        long long int x[length + 1] = {};
        long long int y[length + 1] = {};
        for (int i = 0; i < length; i++)
        {
            scanf("%lld %lld", &x[i], &y[i]);
        }
        sort(x, 0, length-1);
        sort(y, 0, length-1);
        long long int lastX = x[0], lastY = y[0];
        long long int minX = 0, minY = 0;
        for(int j = 1; j < length; j++){
            if(lastX == x[j]){
                lastX = x[j+1];
                j++;
            }else{
                minX = lastX;
                break;
            }
        }
        for(int j = 1; j < length; j++){
            if(lastY == y[j]){
                lastY = y[j+1];
                j++;
            }else{
                minY = lastY;
                break;
            }
        }
        printf("Case #%d: %lld %lld\n",j, minX, minY);
    }
}