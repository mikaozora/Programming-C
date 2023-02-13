#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 26

// const int SIZE = 26;

struct Food
{
    char name[100];
    int price;
    struct Food *next, *prev;
};

struct Table
{
    struct Food *head, *tail;
} *table[SIZE];

void initializeTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        table[i] = (Table *)malloc(sizeof(Table));
        table[i]->head = table[i]->tail = NULL;
    }
    return;
}

Food *createFood(const char name[100], int price)
{
    Food *temp = (Food *)malloc(sizeof(Food));
    strcpy(temp->name, name);
    temp->price = price;
    temp->next = temp->prev = NULL;
    return temp;
}

void view()
{
    for (int i = 0; i < SIZE; i++)
    {
        Food *curr = table[i]->head;
        printf("%d. ", i);
        while (curr)
        {
            printf("%s %d -> ", curr->name, curr->price);
            curr = curr->next;
        }
        printf("\n");
    }
}

// division method: key % SIZE
int hash(const char name[100])
{
    char firstChar = name[0];
    if (firstChar >= 'A' && firstChar <= 'Z')
    {
        return (firstChar - 'A') % SIZE;
    }
    else if (firstChar >= 'a' && firstChar <= 'z')
    {
        return (firstChar - 'a') % SIZE;
    }
    return firstChar % SIZE;
}

void pushHead(int key, struct Food *newFood)
{
    if (!table[key]->head)
    {
        table[key]->head = table[key]->tail = newFood;
    }
    else
    {
        newFood->next = table[key]->head;
        table[key]->head->prev = newFood;
        table[key]->head = newFood;
    }
    return;
}

void pushTail(int key, struct Food *newFood)
{
    if (!table[key]->tail)
    {
        table[key]->head = table[key]->tail = newFood;
    }
    else
    {
        newFood->prev = table[key]->tail;
        table[key]->tail->next = newFood;
        table[key]->tail = newFood;
    }
    return;
}

void pushMid(int key, Food *newFood)
{
    Food *curr = table[key]->head;
    while (curr && strcmp(newFood->name, curr->next->name) >= 0)
    {
        curr = curr->next;
    }
    newFood->next = curr->next;
    newFood->prev = curr;
    curr->next = newFood;
    newFood->next->prev = newFood;
}

void insertFood(const char name[100], int price)
{
    int key = hash(name);
    Food *newFood = createFood(name, price);
    if (!table[key]->head || strcmp(name, table[key]->head->name) < 0)
    {
        pushHead(key, newFood);
    }
    else if (strcmp(name, table[key]->tail->name) >= 0)
    {
        pushTail(key, newFood);
    }
    else
    {
        pushMid(key, newFood);
    }
}

void popHead(int key){
    if(!table[key]->head){
        return;
    }else if(table[key]->head == table[key]->tail){
        free(table[key]->head);
        table[key]->head = table[key]->tail = NULL;
    }else{
        Food *newHead = table[key]->head->next;
        newHead->prev = NULL;
        free(table[key]->head);
        table[key]->head = newHead;
    }
}

void popTail(int key){
    if(!table[key]->tail){
        return;
    }else if(table[key]->head == table[key]->tail){
        free(table[key]->head);
        table[key]->head = table[key]->tail = NULL;
    }else{
        Food *newTail = table[key]->tail->prev;
        newTail->next = NULL;
        free(table[key]->tail);
        table[key]->tail = newTail;
    }
}

void popMid(int key, const char name[100]){
    Food *curr = table[key]->head;
    while(curr && strcmp(name, curr->name) != 0){
        curr = curr->next;
    }
    if(!curr){
        printf("Data not found at mid\n");
        return;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
    curr = NULL;
    return;
}



void deleteFood(const char name[100]){
    int key = hash(name);
    if(!table[key]->head && !table[key]->tail){
        printf("Data not found\n");
        return;
    }else if(strcmp(name, table[key]->head->name) == 0){
        popHead(key);
    }else if(strcmp(name, table[key]->tail->name) == 0){
        popTail(key);
    }else{
        popMid(key, name);
    }
    return;
}

int main()
{
    initializeTable();
    // view();
    insertFood("baso aci", 10000);
    insertFood("baso aaaa", 15000);
    insertFood("baso keju", 15000);
    insertFood("baso ikan", 20000);
    insertFood("Nasgor singapor", 18000);
    insertFood("Nasgor hongkong", 18000);
    insertFood("Nasgor jawa", 18000);
    deleteFood("baso aaaa");
    deleteFood("Nasgor jawa");
    deleteFood("coki coki");
    view();
    // printf("%s %d\n", table[1]->head->name, table[1]->head->price);
}