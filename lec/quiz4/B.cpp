#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[1001];
    for(int i = 1; i <= n; i++){
        scanf("%s", str);
        printf("Case %d: ", i);
        int min = 0;
        for(int j = 0; j < strlen(str); j++){
            printf("%s%d", (min == 0? "" : "-"),str[j]);
            min++;
        }
        printf("\n");
    }
}