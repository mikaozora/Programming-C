#include <stdio.h>
#include <math.h>

int min(int num1, int num2) 
{
    return (num1 > num2 ) ? num2 : num1;
}

int findMinRec(int arr[], int i, int sumCalculated, int sumTotal){
    if(i == 0){
        return abs((sumTotal-sumCalculated) - sumCalculated);
    }

    return min(findMinRec(arr, i-1, sumCalculated+arr[i-1], sumTotal), findMinRec(arr, i-1, sumCalculated, sumTotal));
}

int findMin(int arr[], int length){
    int sumTotal = 0;
    for(int i = 0; i < length; i++){
        sumTotal += arr[i];
    }
    return findMinRec(arr, length, 0, sumTotal);
}

int main(){
    int length;
    scanf("%d", &length);
    int arr[length+1] = {};
    for(int i = 0; i < length; i++){
        scanf("%d", &arr[i]);
    }
    printf("min different : %d", findMin(arr, length));
}