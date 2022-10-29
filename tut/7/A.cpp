#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[100][100] = {};
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    int space = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j< n; j++){
            printf("%s%d", (space == 0 ? "" : " "),arr[j][i]);
            space++;
        }
        printf("\n");
        space = 0;
    }
}