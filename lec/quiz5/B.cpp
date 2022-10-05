#include <stdio.h>
#include <string.h>

int main(){
    int ascii[130] = {0};
    char str[1000001];
    int vocal = 0;
    int consonant = 0;
    scanf("%[^\n]", str);
    getchar();
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == 'a' || str[i] == 'i' ||str[i] == 'u' ||str[i] == 'e' ||str[i] == 'o'){
            if(ascii[str[i]] == 0){
                vocal++;
                ascii[str[i]] = 1;
            }
        }else if(str[i] != ' '){
            if(ascii[str[i]] == 0){
                consonant++;
                ascii[str[i]] = 1;
            }
        }
    }
    printf("Vocal: %d\nConsonant: %d\n", vocal, consonant);
}