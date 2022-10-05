#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[1001];
    for(int i = 1; i <= n; i++){
        int temp;
        scanf("%s", str);
        int x = strlen(str);
        for(int j = 0; j < x/2; j++){
            temp = str[j];
            str[j] = str[x-j-1];
            str[x-j-1] = temp; 
        }
        printf("Case %d: ", i);
        for(int j = 0; j < x; j++){
            printf("%d", str[j]%2);
        }
        printf("\n");
    }
}