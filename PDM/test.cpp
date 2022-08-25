#include <stdio.h>

// A
// int main(){
//     float n, result;
//     do
//     {
//         scanf("%f", &n);
//         if(n >= 0){
//             result += n;
//         }
//     } while (n >= 0);
//     printf("%.2f", result);
// }

// B
int main()
{
    float n, max = 0, min = 0;
    do
    {
        scanf("%f", &n);
        if (n >= max)
        {
            max = n;
        }
        else if (n == -99)
        {
            break;
        }
        else if (n <= min)
        {
            min = n;
        }
    } while (n != -99);
    printf("max: %.2f\n", max);
    printf("min : %.2f\n", min);
}