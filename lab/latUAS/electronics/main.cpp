#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

double space = 150;
int eCount = 0;

struct electronics
{
    char name[256];
    char type[256];
    int price;
    int stock;
} elec[150];

void swap(int a, int b)
{
    electronics temp;
    temp = elec[a];
    elec[a] = elec[b];
    elec[b] = temp;
}

int partition(int low, int high)
{
    char pivot[256] = {};
    strcpy(pivot, elec[high].name);
    int i = low - 1;
    int j = low;
    while (j < high)
    {
        if (strcmpi(elec[j].name, pivot) < 0)
        {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i + 1, high);
    return i + 1;
}

void sort(int low, int high)
{
    if (low < high)
    {
        int part = partition(low, high);
        sort(low, part - 1);
        sort(part + 1, high);
    }
}

int search(char *name)
{
    int left = 0;
    int right = eCount - 1;
    if (eCount == 0)
    {
        return -1;
    }
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (strcmp(name, elec[mid].name) == 0)
        {
            return mid;
        }
        else if (strcmp(name, elec[mid].name) < 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

void menu()
{
    printf("Electronics 2.0!\n");
    printf("==================\n");
    printf("1. Insert Electronic Stock\n");
    printf("2. View Electronic List\n");
    printf("3. Sell Electronic\n");
    printf("4. Exit\n");
    printf(">> ");
}

void importData()
{
    FILE *file;
    file = fopen("electronic.txt", "r");

    char name[256] = {};
    char type[256] = {};
    int price;
    int stock;
    while (!feof(file))
    {
        fscanf(file, "%[^#]#%[^#]#%d#%d\n", elec[eCount].name, elec[eCount].type, &elec[eCount].price, &elec[eCount].stock);
        if (strcmp(elec[eCount].type, "Small") == 0)
        {
            space -= elec[eCount].stock * 1;
        }
        else if (strcmp(elec[eCount].type, "Medium") == 0)
        {
            space -= elec[eCount].stock * 2;
        }
        else
        {
            space -= elec[eCount].stock * 4;
        }
        eCount++;
    }

    fclose(file);
}

void viewAll()
{
    double percent = 0;
    percent = ((150 - space) / 150) * 100;
    printf("==========================================================================\n");
    printf("| Electronic Name \t | Electronic Type \t | Price \t | Stock |\n");
    printf("==========================================================================\n");
    for (int i = 0; i < eCount; i++)
    {
        printf("| %-22s | %-21s | Rp.%-10d | %-5d |\n", elec[i].name, elec[i].type, elec[i].price, elec[i].stock);
    }
    printf("==========================================================================\n");
    printf("| Used Capacity Percentage \t\t\t\t\t | %.1lf%% |\n", percent);
    printf("==========================================================================\n");
    printf("Press enter to continue...");
    getchar();
}

void sell()
{
    printf("==========================================================================\n");
    printf("| Electronic Name \t | Electronic Type \t | Price \t | Stock |\n");
    printf("==========================================================================\n");
    for (int i = 0; i < eCount; i++)
    {
        printf("| %-22s | %-21s | Rp.%-10d | %-5d |\n", elec[i].name, elec[i].type, elec[i].price, elec[i].stock);
    }
    printf("==========================================================================\n");
    char input[256] = {};
    int index;
    do
    {
        do
        {
            printf("Input Electronic Name you want to sell [input \"back\" to back]: ");
            scanf("%[^\n]", input);
            getchar();
            if (strcmp(input, "back") == 0)
            {
                break;
            }
            index = search(input);
        } while (index == -1);
        if (strcmp(input, "back") == 0)
        {
            break;
        }
        int qty;
        do
        {
            printf("Input item quantity you want to sell [1-%d]: ", elec[index].stock);
            scanf("%d", &qty);
            getchar();
        } while (qty < 1 || qty > elec[index].stock);
        printf("\n\nSuccesfully Sold Item!\n");
        printf("========================\n");
        printf("Transaction Details\n");
        printf("========================\n");
        printf("Electronic Name: %s\n", elec[index].name);
        printf("Electronic Type: %s\n", elec[index].type);
        printf("Quantity: %d\n", qty);
        printf("Total Price: %d\n", qty * elec[index].price);
        if (strcmp(elec[index].type, "Small") == 0)
        {
            space += qty * 1;
        }
        else if (strcmp(elec[index].type, "Medium") == 0)
        {
            space += qty * 2;
        }
        else
        {
            space += qty * 4;
        }
        if (elec[index].stock - qty == 0)
        {
            for (int i = index; i < eCount; i++)
            {
                elec[i] = elec[i + 1];
            }
            eCount--;
        }
        else
        {
            elec[index].stock -= qty;
        }
        printf("Press enter to continue...");
        getchar();
    } while (index == -1);
}

void save()
{
    FILE *file;
    file = fopen("electronic.txt", "w");

    for (int i = 0; i < eCount; i++)
    {
        fprintf(file, "%s#%s#%d#%d\n", elec[i].name, elec[i].type, elec[i].price, elec[i].stock);
    }

    fclose(file);
}

void newItem()
{
    if (space == 0)
    {
        printf("There is no spaces left\n");
    }
    char name[256] = {};
    char type[256] = {};
    int price;
    int stock;
    int index;
    do
    {
        printf("Input item name [5 - 25 Characters | Unique]: ");
        scanf("%[^\n]", name);
        getchar();
        index = search(name);
    } while (strlen(name) < 5 || strlen(name) > 25 || index != -1);
    do
    {
        printf("Input item type [Small | Medium | Big]: ");
        scanf("%s", type);
    } while (strcmp(type, "Small") != 0 && strcmp(type, "Medium") != 0 && strcmp(type, "Big") != 0);
    int max = 0;
    if (strcmp(type, "Small") == 0)
    {
        max = 200000;
    }
    else if (strcmp(type, "Medium") == 0)
    {
        max = 1500000;
    }
    else
    {
        max = 10000000;
    }
    do
    {
        printf("Input item price [max %d]: ", max);
        scanf("%d", &price);
        getchar();
    } while (price < 0 || price > max);
    int temp = 0;
    do
    {
        printf("Input item stock [more than 0]: ");
        scanf("%d", &stock);
        getchar();
        if (strcmp(type, "Small") == 0)
        {
            temp = stock * 1;
        }
        else if (strcmp(type, "Medium") == 0)
        {
            temp = stock * 2;
        }
        else
        {
            temp = stock * 4;
        }
        if (temp > space)
        {
            printf("Input stock is more than available capacity [%.0lf spaces]!\n", space);
        }
    } while (stock <= 0 || temp > space);
    strcpy(elec[eCount].name, name);
    strcpy(elec[eCount].type, type);
    space -= temp;
    elec[eCount].price = price;
    elec[eCount].stock = stock;
    eCount++;
    sort(0, eCount - 1);
    printf("Succesfully inserted new item!\n");
    printf("Press enter to continue...");
    getchar();
}

void existItem()
{
    if (space == 0)
    {
        printf("There is no spaces left\n");
    }
    printf("==========================================================================\n");
    printf("| Electronic Name \t | Electronic Type \t | Price \t | Stock |\n");
    printf("==========================================================================\n");
    for (int i = 0; i < eCount; i++)
    {
        printf("| %-22s | %-21s | Rp.%-10d | %-5d |\n", elec[i].name, elec[i].type, elec[i].price, elec[i].stock);
    }
    printf("==========================================================================\n");
    char input[256] = {};
    int index;
    do
    {
        do
        {
            printf("Input Electronic Name you want to add stock [Input \"back\" to back: ");
            scanf("%[^\n]", input);
            getchar();
            if (strcmp(input, "back") == 0)
            {
                break;
            }
            index = search(input);
            if (index == -1)
            {
                printf("Please input existing electronic name!\n");
            }
        } while (index == -1);
        if (strcmp(input, "back") == 0)
        {
            break;
        }
        int qty;
        int temp;
        do
        {
            printf("Input how many stock you want to add: ");
            scanf("%d", &qty);
            getchar();
            if (strcmp(elec[index].type, "Small") == 0)
            {
                temp = qty * 1;
            }
            else if (strcmp(elec[index].type, "Medium") == 0)
            {
                temp = qty * 2;
            }
            else
            {
                temp = qty * 4;
            }
            if (temp > space)
            {
                printf("Input stock is more than available capacity [%.0lf spaces]!\n", space);
            }
        } while (qty < 0 || temp > space);
        space -= temp;
        elec[index].stock += qty;
        printf("Succesfully add stock!\n");
        printf("Press enter to continue...");
        getchar();
    } while (index == -1);
}

void insertMenu()
{
    int n;
    do
    {
        printf("Select this two option\n");
        printf("1. Insert new item\n");
        printf("2. Add existing item stock\n");
        printf("0. Back\n");
        printf(">> ");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 0:
            break;
        case 1:
            newItem();
            break;
        case 2:
            existItem();
            break;
        }
    } while (n != 0);
}

int main()
{
    int n;
    importData();
    do
    {
        printf("%.1lf\n", space);
        menu();
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            system("cls");
            insertMenu();
            system("cls");
            break;
        case 2:
            system("cls");
            viewAll();
            system("cls");
            break;
        case 3:
            system("cls");
            sell();
            system("cls");
            break;
        case 4:
            save();
            break;
        default:
            printf("Please input a valid number\n");
            break;
        }
    } while (n != 4);
}