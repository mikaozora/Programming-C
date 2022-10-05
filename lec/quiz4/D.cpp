#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
    int n, x, y, ascii;
    scanf("%d %d", &n, &x);
    char str[n];
    scanf("%s", str);
    for(int i = 0; i < x; i++){
        scanf("%d", &y);
        ascii = str[y];
        if(ascii >= 65 && ascii <= 90){
            str[y] += 32;
        }else if(ascii >= 97 && ascii <= 122){
            str[y] -= 32;
        }
    }
    // str[0] -= 32;
    printf("%s\n", str);
}