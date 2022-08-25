#include <stdio.h>
#include <ctype.h>
#include <math.h>

// even(genap) or odd number(ganjil)
// int main()
// {
//     int angka;
//     printf("masukkan angka: ");
//     scanf("%d", &angka);
//     if (angka % 2 == 0)
//     {
//         printf("angka adalah bilangan genap");
//     }
//     else
//     {
//         printf("angka adalah bilangan ganjil");
//     }
// }

// check char is vowel(vokal) or consonant(konsonan)
// int main()
// {
//     char alpha;
//     char result;
//     printf("masukkan character: ");
//     scanf("%c", &alpha);
//     result = tolower(alpha);
//     if (!isalpha(alpha))
//     {
//         printf("non alphabet\n");
//     }
//     else
//     {
//         printf("alphabet\n");
//         if (result == 'a' || result == 'i' || result == 'u' || result == 'e' || result == 'o')
//         {
//             printf("%c is vowel", alpha);
//         }
//         else
//         {
//             printf("%c is consonant", alpha);
//         }
//     }
// }

// Find the Roots of a Quadratic Equation // mencari akar dari persamaan kuadrat
// int main(){
//     double a, b, c, root1, root2, discriminant;
//     scanf("%lf %lf %lf", &a, &b, &c);
//     discriminant = pow(b, 2) - 4 * a * c;
//     if(discriminant > 0 ){
//         root1 = (-b + sqrt(discriminant) / 2 * a);
//         root2 = (-b - sqrt(discriminant) / 2 * a);
//         printf("root 1 is %lf and root 2 is %lf", root1, root2);
//     }else if(discriminant == 0){
//         root1 = (-b / 2 * a);
//         root2 = root1;
//         printf("root 1 and root 2 is %lf", root1);
//     }else{
//         printf("imajiner");
//     }
// }

int main(){
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    if(a > b && a > c){
        printf("a the biggest");
    }else if( b> a && b > c){
        printf("b the biggest");
    }else if( c > a && c> b){
        printf(" c the biggest");
    }else{
        printf("there is no the biggest");
    }
}