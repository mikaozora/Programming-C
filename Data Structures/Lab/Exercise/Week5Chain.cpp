#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 26;

struct Node
{
    char name[256];
    int age;
    Node *next, *prev;
};

struct Row
{
    Node *head, *tail;
} *table[SIZE];

Node *createNode(const char *name, int age)
{
    Node *node = (Node *)malloc(sizeof(Node));
    strcpy(node->name, name);
    node->age = age;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Row *createRow()
{
    Row *row = (Row *)malloc(sizeof(Row));
    row->head = row->tail = NULL;
    return row;
}

void viewAll()
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d. ", i);
        Row *row = table[i];
        if (row)
        {
            Node *curr = row->head;
            while (curr)
            {
                printf("%s - %d -> ", curr->name, curr->age);
                curr = curr->next;
            }
            printf("\n");
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
        table[key] = createRow();
        table[key]->head = table[key]->tail = createNode(name, age);
        return;
    }
    Node *node = createNode(name, age);
    node->prev = table[key]->tail;
    table[key]->tail->next = node;
    table[key]->tail = node;
}

void deleteNode(const char *name)
{
    int key = hash(name);
    if (!table[key])
    {
        printf("not found\n");
        return;
    }
    if (strcmp(table[key]->head->name, name) == 0)
    {
        if (table[key]->head == table[key]->tail)
        {
            free(table[key]->head);
            table[key]->head = table[key]->tail = NULL;
            free(table[key]);
            table[key] = NULL;
        }
        else
        {
            Node *temp = table[key]->head;
            table[key]->head = table[key]->head->next;
            table[key]->head->prev = NULL;
            free(temp);
            temp = NULL;
        }
    }
    else if (strcmp(table[key]->tail->name, name) == 0)
    {
        Node *temp = table[key]->tail;
        table[key]->tail = table[key]->tail->prev;
        table[key]->tail->next = NULL;
        free(temp);
        temp = NULL;
    }
    else
    {
        Node *curr = table[key]->head;
        while (strcmp(curr->name, name) != 0 && curr != table[key]->tail)
        {
            curr = curr->next;
        }
        if (curr == table[key]->tail)
        {
            printf("Data not found\n");
            return;
        }
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        free(curr);
        curr = NULL;
    }
}

int main()
{
    insertNode("jason", 10);
    insertNode("sham", 15);
    insertNode("ruth", 20);
    insertNode("javier", 10);
    insertNode("samor", 15);
    insertNode("ravi", 20);
    insertNode("jacky", 10);
    insertNode("sapien", 15);
    insertNode("revo", 20);
    deleteNode("sham");
    deleteNode("ravi");
    viewAll();

    return 0;
}