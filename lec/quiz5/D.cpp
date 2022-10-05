#include <stdio.h>
#include <string.h>


int main(){
    int n;
    scanf("%d", &n);
    int arr[101];
    int arr2[101];
    int temp;
    int count = 0;
    for(int i = 0; i < n+1; i++){
        arr[i] = n;
    }
    for(int i = 0; i < n+1; i++){
        if(i == 0){
            arr2[i] = n;
        }else{
            arr2[i] = 0;
        }
    }
    for(int i = 0; i < n*n; i++){
        scanf("%d", &temp);
        arr2[temp]++;
    }
    for(int i = 0; i < n+1; i++){
        if(arr2[i] < arr[i]){
            count++;
        }
    }
    printf("%d\n", count);
}