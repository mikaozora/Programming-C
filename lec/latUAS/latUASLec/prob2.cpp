#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j = low;
    while (j < high)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

void sort(int arr[], int low, int high)
{
    if(low < high){
        int part = partition(arr, low, high);
        sort(arr, low, part-1);
        sort(arr, part+1, high);
    }
}

int search(int arr[], int size, int start, int target, int pivot){
    int left = start; 
    int right = size-1;
    while(left <= right){
        int mid = (right+left)/2;
        int temp = target - pivot;
        if(temp <= 0){
            return 0;
        }
        if(arr[mid] == temp && arr[mid] > pivot){
            return 1;
        }
        if(arr[mid] > temp){
            right = mid-1;
        }else{
            left = mid+1;
        }
    }
    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n + 1] = {};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",  arr[i]);
    // }
    int target;
    scanf("%d", &target);
    int last = 0, count = 0;
    for(int j = 0; j < n; j++){
        if(arr[j] == last){
            continue;
        }
        if(target - arr[j] <= 0){
            break;
        }
        count += search(arr, n, j, target, arr[j]);
        last = arr[j];
       
    }
    printf("Count : %d", count);
}