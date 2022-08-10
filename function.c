#include <stdio.h>
#include <math.h>
#include <string.h>

// int add(int a, int b){
//     return a + b;
// }
// int multiply(int a, int b);

// int main(){
//     int x, y;
//     printf("masukkan nilai x: ");
//     scanf("%d", &x);
//     printf("masukkan nilai y: ");
//     scanf("%d", &y);
//     printf("x + y = %d\n", add(x, y));
//     printf("x x y = %d", multiply(x, y));
// }

// int multiply(int a, int b){
//     return a * b;
//}

//recursion
// int factorial(int n){
//     if(n > 1){
//         return n * factorial(n-1);
//     }else{
//         return n;
//     }
// }

// int main(){
//     int a;
//     scanf("%d", &a);
//     printf("result: %d", factorial(a));
// }

//bilangan prima antara 2 integer
// int cekprima(int a, int b);

// int main(){
//     int a, b, temp;
//     scanf("%d %d", &a, &b);
//     if(a > 0 || b > 0){
//         if(a > b){
//         temp = a;
//         a = b;
//         b = temp;
//     }
//     cekprima(a, b);
//     }else{
//         printf("masukkan bilangan integer positif");
//     }
    
// }

// int cekprima(int a, int b){
//     int n = 1;
//     for(int i = a+1; i < b; i++){
//         // printf("%d ", i);
//         for(int j = 2; j <= i/2; j++){
//             // printf("%d ", i);
//             if(i % j == 0){
//                 n = 0;
//                 break;
//             }
//             n = 1;
//         }
//         if(n == 1){
//             printf("%d ", i);
//         }
//     }
// }

//convert binary to decimal, octal, hexadecimal
// int main(){
//     long long bin;
//     int decimal = 0, octal = 0, hexa = 0, i = 0;
//     printf("masukkan bilangan biner: ");
//     scanf("%lld", &bin);

//     //to decimal
//     while(bin != 0){
//         decimal += (bin % 10) * pow(2, i);
//         bin /= 10;
//         i++;
//     }
//     printf("decimal: %d\n", decimal);
//     // to hexa
//     printf("hexadecimal: %x\n", decimal);
//     i = 1; //reset 
//     //to octal
//     while(decimal != 0){
//         octal += (decimal % 8) * i;
//         decimal /= 8;
//         i *= 10;
//     }
//     printf("octal: %d\n", octal);
// }

//convert decimal to binary, octal, hexadecimal
void dectobin(int n){
    int i = 0;
    int bin[32];
    while(n > 0){
        bin[i] = n % 2;
        i++;
        n /= 2;
    }
    printf("biner: ");
    for(int j = i - 1; j >= 0; j--){
        printf("%d", bin[j]);
    }
    printf("\n");
}
// int main(){
//     int decimal;
//     int octal = 0, hexa = 0, i = 1;
//     printf("masukkan bilangan decimal: ");
//     scanf("%d", &decimal);
//     printf("hexadecimal: %x\n", decimal);
//     //to binary
//     dectobin(decimal);
//     //to octal
//     while(decimal != 0){
//         octal += (decimal % 8) * i;
//         i *= 10;
//         decimal /= 8;
//     }
//     printf("octal: %d", octal);

//     // to binary
//     // while(decimal != 0){
//     //     bin += (decimal  % 2) * i;
//     //     i *= 10;
//     //     decimal /= 2;
//     // }
//     // printf("binary: %lld", bin);
// }

// convert octal to binary, decimal, hexa
// int main(){
//     int octal = 0, decimal = 0, hexa = 0;
//     printf("masukkan bilangan octal: ");
//     scanf("%d", &octal);
//     // to decimal
//     int i = 0;
//     while(octal > 0){
//         decimal += (octal % 10) * pow(8, i);
//         i++;
//         octal /= 10;
//     }
//     printf("decimal: %d\n", decimal);
//     printf("hexadecimal: %x\n", decimal);
//     dectobin(decimal);
// }

// hexa to binary, octal, decimal
int main(){
    int decimal = 0, octal = 0, length = 0, base = 1;
    char hexa[20];
    printf("masukkan bilangan hexadecimal: ");
    scanf("%s", hexa); getchar();
    length = strlen(hexa);
    for(int i = length - 1; i >= 0; i--){
        if(hexa[i] >= '0' && hexa[i] <= '9'){
            decimal += (hexa[i] - 48) * base;
            base *= 16; 
        }else if(hexa[i] >= 'A' && hexa[i] <= 'F'){
            decimal += (hexa[i] - 55) * base;
            base *= 16;
        }else if(hexa[i] >= 'a' && hexa[i] <= 'f'){
            decimal += (hexa[i] - 87) * base;
            base *= 16;
        }
    }
    printf("decimal: %d\n", decimal);
    //to biner
    dectobin(decimal);
    //to octal
    int i = 1;
    while(decimal > 0){
        octal += (decimal % 8) * i;
        i *= 10;
        decimal /= 8;
    }
    printf("octal: %d", octal);
} 