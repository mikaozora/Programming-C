#include<stdio.h>

int main(){
 int test, A, B;
 
 scanf("%d", &test);
 for(int i=0; i<test; i++){
  scanf("%d %d", &A, &B);
  
  while (A != 1 && B != A){
   if(A % 2 == 0){
    A = A/2;
   } else if(A%2 == 1){
    A = (A*3) + 1;
   }
  }
  
  if (B == A){
   printf("Case #%d: ", i+1);
   printf("YES\n");
  } else{
   printf("Case #%d: ", i+1);
   printf("NO\n");
  }
 }
 
 
 return 0;
}