#include <stdio.h>

//if else condition
// int main(){
//     int num1 = 3;
//     int num2 = 3;
//     if(num1 < num2){
//         printf("true");
//     }else if(num1 > num2){
//         printf("true mint");
//     }else{
//         printf("hayoo bingung lu\n");
//     }
//     int x = 100;
//     (x >= 100) ? printf("true mint") : printf("false");
// }

//switch case 
// int main(){
//     int day = 8;
//     switch(day){
//         case 1 :
//             printf("senin");
//             break;
//         case 2 :
//             printf("selasa");
//             break;
//         case 3 :
//             printf("rabu");
//             break;
//         case 4 :
//             printf("kamis");
//             break;
//         case 5 :
//             printf("jumat");
//             break;
//         case 6 :
//             printf("sabtu");
//             break;
//         case 7 :
//             printf("senin");
//             break;
//         default:
//             printf("hari libur wkwk");
//     }
//}

//bilangan prima
int main(){
    int a, result = 1;
    scanf("%d", &a);
    if(a > 0){
        if(a == 0 || a == 1 ){
            printf("a merupakan bilangan prima");
            return 0;
        }
        for(int i = 2; i <= a/2; i++){
            if(a % i == 0){
                result = 0;
            }
        }
        if(result == 0){
            printf("a bukan merupakan bilangan prima");
        }else{
            printf("a merupakan bilangan prima");
        }
    }
    else{
        printf("masukkan bilangan positif integer");
    }
}