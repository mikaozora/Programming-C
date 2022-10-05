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
// int main()
// {
//     float n, max = 0, min = 0;
//     do
//     {
//         scanf("%f", &n);
//         if (n >= max)
//         {
//             max = n;
//         }
//         else if (n == -99)
//         {
//             break;
//         }
//         else if (n <= min)
//         {
//             min = n;
//         }
//     } while (n != -99);
//     printf("max: %.2f\n", max);
//     printf("min : %.2f\n", min);
// }

// sl 5
double validGram(double grams)
{
    while (grams < 0)
    {
        printf("grams can't less than 0\n");
        scanf("%lf", &grams);
    }
    return grams;
}

double validCalories(double grams, double calories)
{
    while (calories < 0 || calories < grams * 9)
    {
        printf("calories can't less than 0 and caloriest can't greater than grams * 9\n");
        scanf("%lf", &calories);
    }
    return calories;
}

int main()
{
    double grams, calories, result;
    scanf("%lf", &grams);
    grams = validGram(grams);
    printf("---------\n");
    scanf("%lf", &calories);
    calories = validCalories(grams, calories);
    printf("%lf\n", calories);
    result = grams * 9 / calories;
    printf("%lf\n", result);
    if(result < 0.3){
        printf("low in fat");
    }
}