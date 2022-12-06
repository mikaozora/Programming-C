#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int orderCount = 0;
int money = 0;
char friedMenu[4][256] = {"Vegetarian fried rica", "Pork fried rice", "Beef fried rice", "Chicken fried rice"};
char topMenu[3][256] = {"Omellete", "Mozarella", "Cheddar"};

struct orderList
{
    char custName[256];
    char riceName[256];
    char topping[256];
    int price;
    int qty;
} order[100];

void menu()
{
    printf("Random Fried Rice Shop...\n");
    printf("Current money : %d\n", money);
    printf("1. Insert Order\n");
    printf("2. View Order\n");
    printf("3. Make Order\n");
    printf("4. Exit\n");
    printf("Choose > ");
}

void importData()
{
    FILE *file;
    file = fopen("data2.csv", "r");

    char cusName[256];
    char friedName[256];
    char top[256];
    int price;
    int qty;
    int size = 0;
    if (NULL != file)
    {
        fseek(file, 0, SEEK_END);
        size = ftell(file);
        if (0 == size)
        {
            // printf("empty\n");
            return;
        }
        fseek(file, 0, SEEK_SET);
        if (size)
        {
            while (!feof(file))
            {
                fscanf(file, "%[^#]#%[^#]#%[^#]#%d#%d\n", cusName, friedName, top, &price, &qty);
                // printf("%s %s %s %d %d\n", cusName, friedName, top, price, qty);
                strcpy(order[orderCount].custName, cusName);
                strcpy(order[orderCount].riceName, friedName);
                strcpy(order[orderCount].topping, top);
                order[orderCount].price = price;
                order[orderCount].qty = qty;
                orderCount++;
            }
        }
    }

    fclose(file);
}

void insertOrder()
{
    char cusName[256] = {};
    char friedName[256] = {};
    char top[256] = {};
    int price;
    int qty;
    int choose;
    do
    {
        printf("Insert customer name [3 - 50 characters] : ");
        scanf("%[^\n]", cusName);
        getchar();
    } while (strlen(cusName) < 3 || strlen(cusName) > 50);
    strcpy(order[orderCount].custName, cusName);
    do
    {
        printf("Choose fried rice : \n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d. %s\n", i + 1, friedMenu[i]);
        }
        printf("Choose fried rice [1-4] : ");
        scanf("%d", &choose);
        getchar();
    } while (choose < 1 || choose > 4);
    strcpy(order[orderCount].riceName, friedMenu[choose - 1]);
    do
    {
        printf("Choose topping : \n");
        for (int i = 0; i < 3; i++)
        {
            printf("%d. %s\n", i + 1, topMenu[i]);
        }
        printf("Choose topping [1-3] : ");
        scanf("%d", &choose);
        getchar();
    } while (choose < 1 || choose > 3);
    strcpy(order[orderCount].topping, topMenu[choose - 1]);
    do
    {
        printf("Insert quantity of fried rice [1-10] : ");
        scanf("%d", &qty);
        getchar();
    } while (qty < 1 || qty > 10);
    order[orderCount].qty = qty;
    srand(time(NULL));
    int length = strlen(cusName);
    price = ((rand() % (length - 1)) + 1) * 7000;
    order[orderCount].price = price;
    orderCount++;
}

void swap(int a, int b)
{
    struct orderList temp;
    temp = order[a];
    order[a] = order[b];
    order[b] = temp;
}

int partitionPrice(int low, int high)
{
    int pivot = order[high].price;
    int i = low - 1;
    int j = low;
    while (j < high)
    {
        if (order[j].price <= pivot)
        {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i + 1, high);
    return i + 1;
}

void sortPrice(int low, int high)
{
    if (low < high)
    {
        int part = partitionPrice(low, high);
        sortPrice(low, part - 1);
        sortPrice(part + 1, high);
    }
}

int partitionQty(int low, int high)
{
    int pivot = order[high].qty;
    int i = low - 1;
    int j = low;
    while (j < high)
    {
        if (order[j].qty <= pivot)
        {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i + 1, high);
    return i + 1;
}

void sortQty(int low, int high)
{
    if (low < high)
    {
        int part = partitionQty(low, high);
        sortQty(low, part - 1);
        sortQty(part + 1, high);
    }
}

int partitionName(int low, int high)
{
    char pivot[256] = {};
    strcpy(pivot, order[high].custName);
    int i = low - 1;
    int j = low;
    while (j < high)
    {
        if (strcmp(order[j].custName, pivot) < 0)
        {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i + 1, high);
    return i + 1;
}

void sortName(int low, int high)
{
    if (low < high)
    {
        int part = partitionName(low, high);
        sortName(low, part - 1);
        sortName(part + 1, high);
    }
}

void viewOrder()
{
    int choose;
    if (!orderCount)
    {
        printf("There are no data...\nPress any key to continue...");
        getc(stdin);
    }
    else
    {
        do
        {
            for (int i = 0; i < orderCount; i++)
            {
                printf("%d. %s with %s\nOrdered by - %s with quantity of %d, price of %d with total %d\n\n", i + 1,
                       order[i].riceName, order[i].topping, order[i].custName, order[i].qty, order[i].price, order[i].qty * order[i].price);
            }
            printf("1. Order by price\n");
            printf("2. Order by quantity\n");
            printf("3. Order by customer name\n");
            printf("4. Exit\n");
            printf("Choose > ");
            scanf("%d", &choose);
            getchar();
            switch (choose)
            {
            case 1:
                sortPrice(0, orderCount - 1);
                // viewOrder();
                break;
            case 2:
                sortQty(0, orderCount - 1);
                // viewOrder();
                break;
            case 3:
                sortName(0, orderCount - 1);
                // viewOrder();
                break;
            case 4:
                break;
            default:
                break;
            }
        } while (choose != 4);
    }
}

void makeOrder()
{
    // viewOrder();
    for (int i = 0; i < orderCount; i++)
    {
        printf("%d. %s with %s\nOrdered by - %s with quantity of %d, price of %d with total %d\n\n", i + 1,
               order[i].riceName, order[i].topping, order[i].custName, order[i].qty, order[i].price, order[i].qty * order[i].price);
    }
    if (orderCount)
    {
        int choose;
        do
        {
            printf("Choose id to delete[%d - %d] : ", 1, orderCount);
            scanf("%d", &choose);
            getchar();
        } while (choose < 1 || choose > orderCount);
        money += order[choose - 1].price * order[choose - 1].qty;
        for (int i = choose - 1; i < orderCount; i++)
        {
            order[i] = order[i + 1];
        }
        orderCount--;
    }
}

void save()
{
    FILE *file;
    file = fopen("data2.csv", "w");
    for (int i = 0; i < orderCount; i++)
    {
        fprintf(file, "%s#%s#%s#%d#%d\n", order[i].custName, order[i].riceName, order[i].topping, order[i].price, order[i].qty);
    }
    fclose(file);
}

int main()
{
    int n;
    importData();
    do
    {
        menu();
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            insertOrder();
            break;
        case 2:
            viewOrder();
            break;
        case 3:
            makeOrder();
            break;
        case 4:
            save();
            break;
        default:
            printf("Invalid Input...\nPress any key to continue...");
            getc(stdin);
            system("cls");
            break;
        }
    } while (n != 4);
}