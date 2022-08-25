#include <stdio.h>

// *
// * *
// * * *
// * * * *
// int main(){
//     int n;
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++){
//         for(int j = 0; j < i; j++){
//             printf("* ");
//         }
//         printf("\n");
//     }
// }

// 1
// 1 2
// 1 2 3
// int main(){
//     int n;
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= i; j++){
//             printf("%d ", j);
//         }
//         printf("\n");
//     }
// }

// A
// B B
// C C C
// int main(){
//     int n;
//     int alphabet = 65;
//     scanf("%d", &n);
//     for(int i = 1; i <= n; i++){
//         for(int j = 1; j <= i; j++){
//             printf("%c ", alphabet);
//         }
//         alphabet++;
//         printf("\n");
//     }
// }

// * * *
// * *
// *
// int main(){
//     int n;
//     scanf("%d", &n);
//     for(int i = n; i >= 1; i--){
//         for(int j = 1; j <= i; j++){
//             printf("* ");
//         }
//         printf("\n");
//     }
// }

// 1 2 3
// 1 2
// 1
// int main(){
//     int n;
//     scanf("%d", &n);
//     for(int i = n; i >= 1; i--){
//         for(int j = 1; j <= i; j++){
//             printf("%d ", j);
//         }
//         printf("\n");
//     }
// }

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            printf("  ");
        }
        for (int k = 1; k <= (2 * i - 1); k++)
        {
            printf("* ");
        }
        printf("\n");
    }
}
