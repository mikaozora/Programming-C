#include <stdio.h>

int main(){
    // while
    // int i = 0;
    // while(i < 10){
    //     printf("%d\n", i);
    //     i++;
    // }

    //do while
    // int i = 10;
    // do
    // {
    //     printf("%d\n", i);
    //     i--;
    // } while (i >= 0);

    //for
    // for(int i = 0; i <= 5; i++){
    //     for(int j = 0; j <= i; j++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }
    // printf("-----------------------\n");
    // for(int a = 5; a >= 0; a--){
    //     for(int b = 0; b <= a; b++){
    //         printf("*");
    //     }
    //     printf("\n");
    // }

    //break n continue
    // int i = 0;
    // while(i < 10){
    //     if(i == 5){
    //         break;
    //     }
    //     printf("%d", i);
    //     i++;
    // }
    // printf("\n");
    // int j = 0;
    // while(j < 10){
    //     if(j == 5){
    //         j++;
    //         continue;
    //     }
    //     printf("%d", j);
    //     j++;
    // }

    //persegi
    // for(int i = 0; i <= 3; i++){
    //     for(int j = 0; j<=3; j++){
    //         printf(" * ");
    //     }
    //     printf("\n");
    // }

    //factorial
    int a;
    scanf("%d", &a);
    for(int i = a - 1; i > 1; i--){
        a *= i;
    }
    printf("result: %d", a);
}