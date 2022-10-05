#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[1001];
    for(int i = 1; i <= n; i++){
        scanf("%s", str);
        int temp;
        int x = strlen(str);
        for(int j = 0; j < x/2; j++){
            temp = str[j];
            str[j] = str[x-j-1];
            str[x-j-1] = temp;
        }
        printf("Case #%d : %s\n", i, str);
    }
}