#include <stdio.h>

int main(){
    int n, y, row, temp;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &y);
    for(int i = 1; i <= y; i++){
        scanf("%d %d", &row, &temp);
        arr[row-1] = temp;
        printf("Case #%d: ", i);
        int space = 0;
        for(int j = 0; j < n; j++){
            printf("%s%d", (space == 0 ? "" : " ") ,arr[j]);
            space++;
        }
        printf("\n");
    }
}