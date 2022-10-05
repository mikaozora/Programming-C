#include <stdio.h>
#include <string.h>

int main(){
    char str[101];
    int n;
    for(int i = 0; i < 3; i++){
        scanf("%d %s", &n, str); getchar();
        printf("%c%c\n", str[n-1], str[0]);
    }
}