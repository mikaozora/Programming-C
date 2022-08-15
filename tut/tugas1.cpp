#include <stdio.h>
#include <string.h>
#include <ctype.h>

// number 1
// int main(){
//     int n = 1;
//     while(n <= 100){
//         if(n % 5 == 0){
//             printf("%d ", n);
//         }
//         n++;
//     }
// }

// number 2
// int main()
// {
//     int n;
//     int count = 0;
//     int even = 0;
//     scanf("%d", &n);
//     while (even <= n)
//     {
//         if (even % 2 == 0)
//         {
//             printf("%d ", even);
//             count++;
//         }
//         even++;
//     }
//     printf("\ncount : %d", count);
// }

// number 3
// int main(){
//     float result, n;
//     // do
//     // {
//     //     scanf("%f", &n);
//     //     result += n;
//     // } while (n >= 0); //negatif ikut operasi

//     do
//     {
//         scanf("%f", &n);
//         if (n >= 0)
//         {
//             result += n;
//         }

//     } while (n >= 0);

//     printf("%f", result);
// }

// number 4
// int main()
// {
//     int n1, n2, n3, stop;
//     n1 = 1;
//     n2 = 1;
//     scanf("%d", &stop);
//     while (n1 <= stop)
//     {
//         printf("%d ", n1);
//         n3 = n1 + n2;
//         n1 = n2;
//         n2 = n3;
//     } //jika sampai stopping poin n

//     // for(int i = 1; i <= stop; i++){
//     //     printf("%d ", n1);
//     //     n3 = n1 + n2;
//     //     n1 = n2;
//     //     n2 = n3;
//     // } //fibonacci sampai n elemen
// }

// number 5
// int main()
// {
//     int n[5];
//     int max, min;
//     float avg;
//     for (int i = 0; i < 5; i++)
//     {
//         scanf("%d", &n[i]);
//         avg += n[i];
//     }
//     avg /= 5;
//     max = n[0];
//     min = n[0];
//     // find the largest
//     for(int i = 0; i < 5; i++){
//         if(n[i] > max){
//             max = n[i];
//         }
//     }
//     // find the smallest
//     for(int i = 0; i < 5; i++){
//         if(n[i] < min){
//             min = n[i];
//         }
//     }
//     printf("avg: %.2f\n", avg);
//     printf("max: %d\n", max);
//     printf("min: %d\n", min);
// }

// pdm
int main()
{
    char primaryOne[255];
    char primaryTwo[255];
    scanf("%[^\n]", primaryOne);
    getchar();
    scanf("%[^\n]", primaryTwo);
    getchar();
    if (((strcmp(primaryOne, "red") != 0) && (strcmp(primaryOne, "blue") != 0 && (strcmp(primaryOne, "yellow") != 0))) || ((strcmp(primaryTwo, "red") != 0) && (strcmp(primaryTwo, "blue") != 0 && (strcmp(primaryTwo, "yellow") != 0))))
    {
        printf("all input must primary color");
    }
    else
    {
        if ((strcmp(primaryOne, "red") == 0 && strcmp(primaryTwo, "blue") == 0) ||
            (strcmp(primaryOne, "blue") == 0 && strcmp(primaryTwo, "red") == 0))
        {
            printf("The secondary color is purple");
        }
        else if ((strcmp(primaryOne, "red") == 0 && strcmp(primaryTwo, "yellow") == 0) ||
                 (strcmp(primaryOne, "yellow") == 0 && strcmp(primaryTwo, "red") == 0))
        {
            printf("The secondary color is orange");
        }
        else if ((strcmp(primaryOne, "blue") == 0 && strcmp(primaryTwo, "yellow") == 0) ||
                 (strcmp(primaryOne, "yellow") == 0 && strcmp(primaryTwo, "blue") == 0))
        {
            printf("The secondary color is green");
        }
        else
        {
            printf("Can't create a new color");
        }
    }
}
