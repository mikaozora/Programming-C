#include <stdio.h>

int main(){
    int a, b, c, d;
    float resA, resB, resC, resD, result;
    for(int i = 0; i < 3; i++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        resA = (a/1.0) * 2.0;
        resB = (b/2.0) * 4.0;
        resC = (c/3.0) * 6.0;
        resD = (d/4.0) * 4.0;
        result = resA + resB + resC + resD;
        printf("%.2f\n", result);
    }                   
}
