#include <stdio.h>

int main(){
    int row;
    scanf("%d", &row);
    long long int arr[row][row];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < row; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for(int i = 1; i < row-1; i++){
        for(int j = 1; j < row-1; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}