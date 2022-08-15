#include <stdio.h>

int main()
{
    char name[255];
    int age;
    float number1, number2;
    printf("Simple input/output Program\n");
    printf("===========================\n");
    printf("Welcome to \"Algorithm and Programming\"\n");
    printf("Enter your name : ");
    scanf("%[^\n]", name);
    getchar();
    printf("Enter your age : ");
    scanf("%d", &age);
    printf("HI, %s\n", name);
    printf("%s is %d years old\n", name, age);
    printf("Enter the first number : ");
    scanf("%f", &number1);
    printf("Enter the second number : ");
    scanf("%f", &number2);
    printf("arithmathic calculation : \n");
    printf("\t%.2f + %.2f = %.2f\n", number1, number2, number1 + number2);
    printf("\t%.2f - %.2f = %.2f\n", number1, number2, number1 - number2);
    printf("\t%.2f * %.2f = %.2f\n", number1, number2, number1 * number2);
    printf("\t%.2f / %.2f = %.2f\n", number1, number2, number1 / number2);
    int a = number1;
    int b = number2;
    printf("\t%d %% %d = %d\n", a, b, a % b);
}