#include <stdio.h>

void swap(long long int *a, long long int *b){
    long long int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(long long int *arr,int low, int high){
    long long int pivot = arr[high];
    int i = low -1;
    int j = low;

    while(j < high){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void quicksort(long long int *arr,int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        quicksort(arr, low, part-1);
        quicksort(arr, part+1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        long long int arr[30] = {};
        long long int sum = 0;
        for(int j = 0; j < 25; j++){
            scanf("%lld", &arr[j]);
            sum += arr[j];
        }
        // printf("---\n");
        // for(int j = 0; j < 25; j++){
        //     printf("%lld ", arr[j]);
        // }
        // printf("---\n");
        quicksort(arr, 0, 24);
        // for(int j = 0; j < 25; j++){
        //     printf("%lld ", arr[j]);
        // }
        // printf("\n");
        long long int a, b, c, d, e;
        a = arr[0] / 2;
        e = arr[24] / 2;
        b = arr[1] - a;
        d = arr[23] - e;
        c = (sum - (10 * a) - (10 * b) - (10 * d) - (10 * e)) / 10;
        printf("Case #%d: %lld %lld %lld %lld %lld\n", i, a, b, c, d, e);
    }
}