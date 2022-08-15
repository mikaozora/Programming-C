#include <stdio.h>

int main(){
    char nama[255];
    printf("\"hello world\"\n");

    scanf("%s", nama);
    printf("HI, %s\n", nama);
    int umur;
    scanf("%d", &umur);
    printf("umur: %d\n", umur);
    float ipk;
    scanf("%f", &ipk);
    printf("ipk : %f", ipk); 
}