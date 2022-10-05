#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int row, space;
        scanf("%d", &row);
        scanf("%d", &space);
        double arr[row][row] = {};
        int res = row - space + 1;
        double arr2[res][res] = {};
        for(int j = 0; j < row; j++){
            for(int k = 0; k < row; k++){
                scanf("%lf", &arr[j][k]);
            }
        }
        
        for(int j = 0; j < res; j++){
            for(int k = 0; k < res; k++){
                for(int l = j; l < j+space; l++){
                    for(int m = k; m < k+space; m++){
                        arr2[j][k] +=  arr[l][m];
                        // printf("%.1lf ", arr2[l][k]);
                    }
                    // printf("\n");
                }
            }
        }
        for(int j = 0; j < res; j++){
            for(int k = 0; k < res; k++){
                printf("%.2lf ", arr2[j][k]/(space*space));
            }
            printf("\n");
        }
    }
}