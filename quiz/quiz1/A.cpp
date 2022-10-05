#include <stdio.h>
#include <string.h>

int main(){
    int n;
    char str[1001];
    int code[1001];
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s", str);
        // for(int j = 0; j < 1001; j++){
        //     code[j] = 0;
        // }
        for(int j = 0; j < strlen(str); j++){
            if(str[j] >= 'A' && str[j] <= 'D'){
                code[j] = str[j] - 'A';
                str[j] = 'A';
            }else if(str[j] >= 'E' && str[j] <= 'H'){
                code[j] = str[j] - 'E';
                str[j] = 'E';
            }else if(str[j] >= 'I' && str[j] <= 'N'){
                code[j] = str[j] - 'I';
                str[j] = 'I';
            }else if(str[j] >= 'O' && str[j] <= 'T'){
                code[j] = str[j] - 'O';
                str[j] = 'O';
            }else if(str[j] >= 'U' && str[j] <= 'Z'){
                code[j] = str[j] - 'U';
                str[j] = 'U';
            }
            
        }
        printf("Case #%d:\n%s\n", i, str);
        for(int j = 0; j < strlen(str); j++){
            printf("%d", code[j]);
        }
        printf("\n");
    }
}