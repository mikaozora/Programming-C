#include <stdio.h>

// basics pointer
// int main()
// {
//     int var = 5;
//     printf("var = %d\n", var);

//     //get address of var
//     printf("address of var = %p\n", &var);
//     printf("---------------\n");
//     int *pc, c;
//     c = 50;
//     pc = &c;
//     printf("address of c = %d\n", c);
//     printf("pc = %d\n", *pc);
//     *pc = 2; //mengubah value c(pointed) juga
//     printf("address of pc = %d\n", pc); //pc sama dengan address c
//     printf("pc = %d\n", *pc);
//     printf("c = %d", c);
// }

// pointer and array
// int main(){
//     int x[4];
//     for(int i = 0; i < 4; i++){
//         printf("&x[%d] = %p\n", i, &x[i]);
//     }
//     printf("address of x is %p\n", &x); // address of x is equal to addres x[0], &x[i] = x + i; x[i] = *x
//     printf("----------------\n");
//     int y[5], sum = 0;
//     for(int j = 0; j < 5; j++){
//         scanf("%d", y + j);
//         sum += *(y + j);
//     }
//     printf("total: %d", sum);
//     printf("----------------\n");
//     int a[5] = {1,2,3,4,5};
//     int *ptr;
//     ptr = &a[3];
//     printf("ptr: %d\n", *ptr);
//     printf("ptr + 1: %d\n", *(ptr + 1));
//     printf("ptr - 1: %d\n", *(ptr - 1));
// }

// pointer and function
// void swap(int *a, int *b){
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
// void sumPtr(int *a){
//     (*a)++;
// }

// int main(){
//     int a = 5, b = 7;
//     swap(&a, &b);
//     printf("a: %d\t", a);
//     printf("b: %d\n", b);
//     sumPtr(&a);
//     printf("a: %d", a);
// }

int main(){
    int value = 0;
    int* ptr = &value;
    int **dptr = &ptr;
    
}