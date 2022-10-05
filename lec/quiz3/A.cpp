#include <stdio.h>

int main(){
    int row, column;
    scanf("%d %d", &row, &column);
    int arr[row][column];
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int n, y, z, plant;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &y, &z, &plant);
        arr[y-1][z-1] = plant;
    }
    for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            printf("%d", arr[i][j]);
            if(j < column - 1){
                printf(" ");
            }
        }
        printf("\n");
    }
}