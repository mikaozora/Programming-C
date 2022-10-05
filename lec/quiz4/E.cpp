#include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char str[501];
    char str2[501];
    for(int i = 1; i <= n; i++){
        scanf("%s", str);
        strcpy(str2, str);
        int length = strlen(str);
        char temp[501];
        for(int j = 0; j < length/2; j++){
            temp[j] = str[j];
            str[j] = str[length - j - 1];
            str[length - j - 1] = temp[j];
        }
        printf("Case #%d: ", i);
        if(strcmp(str, str2) == 0){
            printf("Yay, it's a palindrome\n");
        }else{
            printf("Nah, it's not a palindrome\n");
        }
    }
}