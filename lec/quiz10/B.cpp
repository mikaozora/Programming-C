#include <stdio.h>

void swap(long long int *a, long long int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(long long int arr[], int low, int high){
    int pivot = arr[high];
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
void sort(long long int arr[], int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        sort(arr, low, part-1);
        sort(arr, part+1, high);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<= n; i++){
        int length;
        scanf("%d", &length);
        long long int arr[101] = {};
        for(int j = 0; j < length; j++){
            scanf("%lld", &arr[j]);
        }
        sort(arr, 0, length-1);
        // for(int j = 0; j < length; j++){
        //     printf("%lld\n", arr[j]);
        // }
        long long int min = arr[length-1];
        for(int j = 0; j < length - 1; j++){
            for(int k = j+1; k < length; k++){
                if(arr[k] - arr[j] <= min){
                    min = arr[k] - arr[j];
                }
            }
        }
        printf("Case #%d: %lld\n", i, min);
    }
}