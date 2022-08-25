#include <stdio.h>

int main() {
   int myNum = 50;
   float myFloat = 50.55;
   char myChar = 'M';
   double myDouble = 23.5000;
   int hasil = myNum + myFloat + myDouble;
   char myName[] = "Satmika Antargata Ozora";
   const float phi = 3.14;
   int r = 7;
   float luasLingkaran = phi * pow(r,2);
   

   printf("%d\n", myNum);
   printf("%f\n", myFloat);
   printf("%c\n", myChar);
   printf("%lf\n", myDouble);
   printf("---------------------\n");
   printf("My first letter on my name is %c", myChar);
   printf("myNum is %d, myFloat is %f, myDouble is %lf\n", myNum, myFloat, myDouble);
   printf("myFloat + myDouble + myNum = %d\n", hasil);
   printf("%s\n", myName);
   printf("%f\n", luasLingkaran);

   myNum %= 2;
   printf("%d", myNum);
}