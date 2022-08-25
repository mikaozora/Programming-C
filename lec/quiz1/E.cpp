#include <stdio.h>

int main(){
    int A, B, C, D, E, F, G;
    scanf("%d", &A);
    scanf("%d %d", &B, &C);
    scanf("%d %d", &D, &E);
    scanf("%d %d", &F, &G);
    printf("%d\n", (B/C) << C);
    printf("%d\n", (D/E) << E);
    printf("%d\n", (F/G) << G);
}