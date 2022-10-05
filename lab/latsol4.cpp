#include <stdio.h>
#include <string.h>

int main()
{
    char name[255];
    int price;
    char listName[19][21] = {};
    int listPrice[19];
    int n;
    int x = 0, y = 0;
    do
    {
        printf("My Wishlist\n");
        printf("=========================================\n");
        printf("| Item Name\t\t| Item Price\t|\n");
        printf("=========================================\n");
        if (x == 0)
        {
            printf("  Need you to fill it :)\n");
        }
        else
        {
            for (int i = 0; i < x; i++)
            {
                printf("|%d %-10s\t\t| Rp.%d\t|\n",i+1, listName[i], listPrice[i]);
            }
        }
        printf("=========================================\n");
        printf("1. Add Item\n");
        printf("2. Exit\n");
        printf(">> ");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            printf("Input item name: ");
            scanf("%[^\n]", name);
            strcpy(listName[x], name);
            getchar();
            printf("Input item price: ");
            scanf("%d", &price);
            getchar();
            listPrice[y] = price;
            ++x;
            ++y;
            if(x == 21){
                printf("You already input maximum 20 data\n");
                n = 2;
                break;
            }
            break;
        case 2:
            printf("Thank you :D\n");
            break;
        default:
            printf("You must input a valid number!\n");
            break;
        }
    } while (n != 2);
}