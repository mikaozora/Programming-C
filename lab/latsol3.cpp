#include <stdio.h>

int main()
{
    int status = 0;
    do
    {
        printf("Shape printer\n");
        printf("=============\n");
        printf("1. Rectangle\n");
        printf("2. Right Triangle (90 degres triangle)\n");
        printf("3. Equilateral Triangle\n");
        printf("4. Exit\n");
        printf(">> ");
        int n;
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            int width, height;
            do
            {
                printf("Input rectangle  Width [must be more than 0]: ");
                scanf("%d", &width);
            } while (width <= 0);
            do
            {
                printf("Input rectangle  Height [must be more than 0]: ");
                scanf("%d", &height);
            } while (height <= 0);
            printf("Result:\n");
            for (int i = 0; i < height; i++)
            {
                for (int j = 0; j < width; j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 2:
            int size;
            do
            {
                printf("Input Right triangle size [must be more than 0]: ");
                scanf("%d", &size);
            } while (size <= 0);
            printf("Result:\n");
            for (int i = 0; i < size; i++)
            {
                for (int j = i; j < size - 1; j++)
                {
                    printf(" ");
                }
                for (int k = 0; k <= i; k++)
                {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 3:
            int sizeEqui;
            do
            {
                printf("Input Equilateral triangle size [must be more than 0 and odd number]: ");
                scanf("%d", &sizeEqui);
            } while (sizeEqui <= 0 || sizeEqui % 2 == 0);
            printf("Result:\n");
            for (int i = 1; i <= sizeEqui / 2 + 1; i++)
            {
                for (int space = i; space <= sizeEqui - (sizeEqui / 2) - 1; space++)
                {
                    printf(" ");
                }
                for (int k = 1; k <= 2 * i - 1; k++)
                {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 4:
            printf("Thank you for using this app!\n");
            status = 1;
            break;
        default:
            printf("You must input valid menu number!\n");
            break;
        }
    } while (status != 1);
}