#include <stdio.h>

long long int search(long long int *arr, long long int length, long long int req){
    int left = 0;
    int right = length - 1;
    int index = -2;
    while(left <= right){
        int mid = (left + right) / 2;
        if(arr[mid] == req){
            index = mid;
            right = mid - 1;
        }else if(arr[mid] > req){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return index;
}

int main(){
    long long int length, n;
    scanf("%lld %lld", &length, &n);
    long long int arr[length+1] = {};
    for(int i = 0; i < length; i++){
        scanf("%lld", &arr[i]);
    }
    long long int req;
    for(int i = 0; i < n; i++){
        scanf("%lld", &req);
        long long int index = search(arr, length, req);
        printf("%lld\n", index+1);
    }
}