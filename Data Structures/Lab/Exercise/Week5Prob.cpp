#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;

struct Node
{
    char name[256];
    int age;
} *table[SIZE];

Node *createNode(const char *name, int age)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->age = age;
    return node;
}

void viewAll()
{
    for (int i = 0; i < SIZE; i++)
    {
        Node *curr = table[i];
        if (curr)
        {
            printf("%d - %s - %d\n", i, curr->name, curr->age);
        }
        else
        {
            printf("-\n");
        }
    }
}

int hash(const char *name)
{
    char c = name[0];
    if (c >= 'A' && c <= 'Z')
    {
        return c - 'A';
    }
    else if (c >= 'a' && c <= 'z')
    {
        return c - 'a';
    }
    return c % SIZE;
}

void insertNode(const char *name, int age)
{
    int key = hash(name);
    if (!table[key])
    {
        table[key] = createNode(name, age);
        return;
    }
    int curr = key + 1;
    while (key != curr && table[curr])
    {
        curr = (curr + 1) % SIZE;
    }
    if (curr == key)
    {
        printf("Table full\n");
        return;
    }

    table[curr] = createNode(name, age);
}

void deleteNode(const char *name)
{
    int key = hash(name);
    if (table[key] && strcmp(table[key]->name, name) == 0)
    {
        free(table[key]);
        table[key] = NULL;
        return;
    }

    int curr = key + 1;
    while (curr != key && (!table[curr] || strcmp(table[curr]->name, name) != 0))
    {
        curr = (curr + 1) % SIZE;
    }
    if (key == curr)
    {
        printf("Data not found\n");
        return;
    }
    free(table[curr]);
    table[curr] = NULL;
}

int main()
{
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    deleteNode("sham");
    deleteNode("budi");
    viewAll();
    
    return 0;
}