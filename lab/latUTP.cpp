#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h> // function getch() ada di sini

void menu()
{
    printf("Electronics!\n");
    printf("=======================\n");
    printf("1. Insert  Electronic Stock\n");
    printf("2. Update Electronic\n");
    printf("3. Sell Electronic\n");
    printf("4. Exit\n");
    printf(">> ");
}
void checkId(int id){
    char str[5] = {};
    sprintf(str, "%d", id);
    for(int i = 0; i < strlen(str); i++){
        if(isdigit(str[i]) == 1){
            fflush(stdin);
        }
    }
}

int main()
{
    int n, ids, i = 0;
    char id[100][7] = {};
    char name[100][26] = {};
    double price[100] = {};
    do
    {
        char enter = '0';
        char strId[7] = {};
        char strName[50] = {};
        int length = 0;
        int item, disc, res = 1;
        char choice[4] = "";
        // system("cls");
        menu();
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            system("cls");
            do
            {
                printf("Input Item Id [must be numeric with exactly 3 digit]: ");
                scanf("%d", &ids); getchar();
                sprintf(strId, "%s%d", "ETC", ids); // kesalahan 1 adalah memilih menggunakan integer over char
                checkId(ids);
            } while ((ids < 100 || ids > 999));
            strcpy(id[i], strId);
            do
            {
                printf("Input Item Name [5-25 characters]: ");
                scanf("%[^\n]", strName);
                getchar();
                length = strlen(strName);
            } while (length < 5 || length > 25);
            strcpy(name[i], strName);
            do
            {
                printf("Input Item Price [not more than 5M]: ");
                scanf("%lf", &price[i]);
                getchar();
            } while (price[i] > 5000000 || price[i] <= 0);
            printf("Item sucessfully inserted!\n");
            printf("Press enter to continue...");
            scanf("%[^\n]", &enter);
            getchar();
            i++;
            break;
        case 2:
            system("cls");
            if (i == 0)
            {
                printf("There is no item yet...\nPress enter to continue...");
                scanf("%[^\n]", &enter);
            }
            else
            {
                printf("=========================================================\n");
                printf("| No. | Id\t| Name\t\t\t| Price\t\t|\n");
                printf("=========================================================\n");
                for (int j = 0; j < i; j++)
                {
                    printf("| %d   | %-7s | %-21s | Rp%-11.2lf |\n", j + 1, id[j], name[j], price[j]);
                }
                printf("=========================================================\n");
                do
                {
                    printf("Which item you want to update [0 to exit][1..%d]: ", i);
                    scanf("%d", &item);
                    if (item == 0)
                    {
                        break;
                    }
                    do
                    {
                        printf("Input Item Id [must be numeric with exactly 3 digit]: ");
                        scanf("%d", &ids);
                        getchar();
                        checkId(ids);
                    } while ((ids < 100 || ids > 999));
                    sprintf(strId, "%s%d", "ETC", ids);
                    strcpy(id[item - 1], strId);
                    do
                    {
                        printf("Input Item Name [5-25 characters]: ");
                        scanf("%[^\n]", strName);
                        getchar();
                        length = strlen(strName);
                    } while (length < 5 || length > 25);
                    strcpy(name[item - 1], strName);
                    do
                    {
                        printf("Input Item Price [not more than 5M]: ");
                        scanf("%lf", &price[item - 1]);
                        getchar();
                    } while (price[item - 1] > 5000000);
                    printf("Item sucessfully Updated!\n");
                    printf("Press enter to continue...");
                    scanf("%[^\n]", &enter);
                    getchar();
                } while (item < 1 || item > i);
            }
            break;
        case 3:
            system("cls");
            if (i == 0)
            {
                printf("There is no item yet...\nPress enter to continue...");
                scanf("%[^\n]", &enter);
            }
            else
            {
                printf("=========================================================\n");
                printf("| No. | Id\t| Name\t\t\t| Price\t\t|\n");
                printf("=========================================================\n");
                for (int j = 0; j < i; j++)
                {
                    printf("| %d   | %-7s | %-21s | Rp%-11.2lf |\n", j + 1, id[j], name[j], price[j]);
                }
                printf("=========================================================\n");
                do
                {
                    printf("Which item you want to sell [0 to exit][1..%d]: ", i);
                    scanf("%d", &item);
                    getchar();
                    srand(time(NULL));
                    disc = rand() % 10 + 1; 
                    if (disc == 1 || disc == 2 || disc == 3)
                    {
                        printf("#######################\n");
                        printf("Customer get discount 25%\n");
                        printf("#######################\n");
                        printf("%s item detail\n", id[item - 1]);
                        printf("==================\n");
                        printf("Item name: %s\n", name[item - 1]);
                        printf("Item price: %.2lf\n", price[item - 1] - (price[item - 1] * 0.25));
                    }
                    else
                    {
                        printf("%s item detail\n", id[item - 1]);
                        printf("==================\n");
                        printf("Item name: %s\n", name[item - 1]);
                        printf("Item price: %.2lf\n", price[item - 1]);
                    }
                } while (item < 1 || item > i);
                do
                {
                    printf("Are you sure want to sell this? [yes|no]: ");
                    scanf("%s", choice);
                    getchar();
                } while (strcmp(choice, "yes") != 0 && strcmp(choice, "no") != 0);
                if (strcmp(choice, "yes") == 0)
                {
                    for (int j = item - 1; j < i; j++)
                    {
                        strcpy(id[j], id[j + 1]);
                        strcpy(name[j], name[j + 1]);
                        price[j] = price[j + 1];
                    }
                    i--;
                    printf("Item successfully sold!\nPress enter to continue...");
                    scanf("%[^\n]", &enter);
                    getchar();
                }
                else
                {
                    printf("Cancel Selling!\nPress enter to continue...");
                    scanf("%[^\n]", &enter);
                    getchar();
                }
            }
            break;
        case 4:
            break;
        default:
            printf("Please input a valid number\n");
            break;
        }
    } while (n != 4);
}
