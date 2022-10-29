#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int size;
        scanf("%d", &size);
        int arr[size][size] = {};
        int result[size] = {};
        for(int y = 0; y < size; y++){
            for(int z = 0; z < size; z++){
                scanf("%d", &arr[y][z]);
                getchar();
            }
        }
        for(int y = 0; y < size; y++){
            for(int z = 0; z < size; z++){
                result[y] += arr[z][y];
            }
        }
        printf("Case #%d: ", i);
        int space = 0;
        for(int y = 0; y < size; y++){
            printf("%s%d", (space == 0 ? "" : " "), result[y]);
            space++;
        }
        printf("\n");
    }
}