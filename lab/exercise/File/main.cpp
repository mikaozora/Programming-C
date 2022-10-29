#include <stdio.h>

struct productList
{
    char name[256];
    int price;
} product[20];

int main()
{
    FILE *file;
    file = fopen("products.txt", "r");
    int index = 0;
    while (!feof(file))
    {
        fscanf(file, "%[^#]#%d", product[index].name, &product[index].price);
        fgetc(file);
        printf("%s %d\n", product[index].name, product[index].price);
        index++;
    }
    fclose(file);

    file = fopen("products.txt", "w");
    scanf("%[^\n]", product[index].name); getchar();
    scanf("%d", &product[index].price); getchar();
    index++;
    for(int i = 0; i < index; i++){
        fprintf(file, "%s#%d\n", product[i].name, product[i].price);
    }


    // file = fopen("products.txt", "a");
    // scanf("%[^\n]", product[index].name); getchar();
    // scanf("%d", &product[index].price);
    // getchar();
    // fprintf(file, "\n%s#%d", product[index].name, product[index].price);
    // index++;
    // fclose(file);
}