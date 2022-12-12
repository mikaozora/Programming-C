#include <stdio.h>
#include <string.h>

struct pc
{
    char mobo[30];
    char processor[50];
    char vga[30];
    int ram;     // GB
    float price; // Rp
} pc[30];
int current = 0;

void insert()
{
    printf("enter mobo: ");
    scanf("%[^\n]", pc[current].mobo);
    getchar();
    printf("enter processor: ");
    scanf("%[^\n]", pc[current].processor);
    getchar();
    printf("enter vga: ");
    scanf("%[^\n]", pc[current].vga);
    getchar();
    printf("enter ram: ");
    scanf("%d", &pc[current].ram);
    getchar();
    printf("enter price: ");
    scanf("%f", &pc[current].price);
    getchar();
    current++;
}

void display()
{
    if (!current)
    {
        printf("There is no data\n");
    }
    else
    {
        printf("=====================================================================================\n");
        printf("%s | %-15s | %-15s | %-15s | %-3s | %-10s |\n", "No.", "Mobo", "Processor", "vga", "RAM", "Price");
        for (int i = 0; i < current; i++)
        {
            printf("%-3d | %-15s | %-15s | %-15s | %-3d | Rp%-10.2f |\n", i + 1, pc[i].mobo, pc[i].processor, pc[i].vga, pc[i].ram, pc[i].price);
        }
    }
}

void modify()
{
    display();
    int n;
    do
    {
        printf("enter data to modify: ");
        scanf("%d", &n);
        getchar();

    } while (n < 1 || n > current);

    n--;
    printf("enter mobo: ");
    scanf("%[^\n]", pc[n].mobo);
    getchar();
    printf("enter processor: ");
    scanf("%[^\n]", pc[n].processor);
    getchar();
    printf("enter vga: ");
    scanf("%[^\n]", pc[n].vga);
    getchar();
    printf("enter ram: ");
    scanf("%d", &pc[n].ram);
    getchar();
    printf("enter price: ");
    scanf("%f", &pc[n].price);
    getchar();
}

void deleteData()
{
    display();
    int n;
    do
    {
        printf("enter data to delete: ");
        scanf("%d", &n);
        getchar();

    } while (n < 1 || n > current);
    n--;
    for(int i = n; i < current; i++){
        pc[i] = pc[i+1];
    }
    current--;
}

int main()
{

    int menu;
    do
    {
        printf("1. display pc data\n");
        printf("2. insert pc data\n");
        printf("3. modify pc data\n");
        printf("4. delete pc data\n");
        printf("5. exit pc data\n");
        printf("Choose >> ");
        scanf("%d", &menu);
        getchar();
        switch (menu)
        {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            modify();
            break;
        case 4:
        deleteData();
            break;
        default:
            break;
        }

    } while (menu != 5);
}