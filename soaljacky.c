#include <stdio.h>
#include <string.h>

int main(){
    char kata[100];
    printf("masukkan kalimat: ");
    scanf("%[^\n]", kata);
    printf("reverse: %s", strrev(kata));
}