#include <stdio.h>

int main(){
    int n, jojo, lili, bibi, a, avg;
    scanf("%d", &n);
    scanf("%d %d %d", &jojo, &lili, &bibi);
    avg = jojo + lili + bibi;
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        avg += a;
    }
    avg /= n+3;
    if(jojo >= avg){
        printf("Jojo lolos\n");
    }else{
        printf("Jojo tidak lolos\n");
    }
    if(lili >= avg){
        printf("Lili lolos\n");
    }else{
        printf("Lili tidak lolos\n");
    }
    if(bibi >= avg){
        printf("Bibi lolos\n");
    }else{
        printf("Bibi tidak lolos\n");
    }
}