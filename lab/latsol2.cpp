#include <stdio.h>
#include <math.h>

int main(){
    float x, result1, result2, result3;
    printf("Operators\n");
    printf("==============\n");
    printf("Input your favorite number : ");
    scanf("%f", &x);
    printf("We will call the number x\n");
    result1 = 2 * x + 3;
    result2 = result1/3 - 4;
    result3 += pow(result2, 2);
    printf("Result 1 : %.2f\n", result1);
    printf("Result 2 : %.2f\n", result2);
    printf("Result 3 : %.2f\n", result3);
    printf("Y = X.\n");
    float *y;
    y = &x;
    if(*y >= 10){
        printf("Y is bigger or equals 10\n");
    }else{
        printf("Y is smaller than 10\n");
    }
    if((int)*y % 2 == 0){
        printf("Y is even\n");
    }else{
        printf("Y is odd\n");
    }

}