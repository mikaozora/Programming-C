#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// double linked list
struct node
{
    char name[256];
    int age;
    struct node *next, *prev;
} *head = NULL, *tail = NULL;

struct node *createNode(char const *name, int age)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    strcpy(temp->name, name);
    temp->age = age;
    temp->next = temp->prev = NULL;
    return temp;
}

void pushHead(struct node *temp)
{
    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void pushTail(struct node *temp)
{
    if (!head)
    {
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void pushMid(struct node *temp)
{
    if (!head || strcmpi(temp->name, head->name) < 0)
    {
        pushHead(temp);
    }
    else if (strcmpi(temp->name, tail->name) >= 0)
    {
        pushTail(temp);
    }
    else
    {
        struct node *curr = head;
        while (strcmp(temp->name, curr->next->name) >= 0)
        {
            curr = curr->next;
            if (!curr->next)
            {
                break;
            }
        }
        temp->next = curr->next;
        curr->next->prev = temp;
        temp->prev = curr;
        curr->next = temp;
    }
}

void display()
{
    struct node *curr = head;
    if (!head)
    {
        printf("No linked list\n");
        return;
    }
    else
    {
        while (curr)
        {
            if (curr->prev && curr->next)
            {
                printf("%s %d |%s %d | %s %d\n", curr->prev->name, curr->prev->age, curr->name, curr->age, curr->next->name, curr->next->age);
            }
            else if (curr->next)
            {
                printf(" - | %s %d | %s %d \n", curr->name, curr->age, curr->next->name, curr->next->age);
            }
            else
            {
                printf(" %s %d | %s %d | - \n", curr->prev->name, curr->prev->age, curr->name, curr->age);
            }
            curr = curr->next;
        }
    }
}

void popHead()
{
    if (!head)
    {
        printf("No linked list\n");
    }
    else
    {
        struct node *del = head;
        head = head->next;
        head->prev = NULL;
        free(del);
    }
}

void popTail()
{
    if (!tail)
    {
        printf("No linked list\n");
    }
    else
    {
        struct node *del = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(del);
    }
}

void popMid(char const *temp)
{
    struct node *curr = head;
    if (!head)
    {
        printf("No linked list\n");
    }
    else if (strcmpi(temp, head->name) == 0)
    {
        popHead();
    }
    else if (strcmpi(temp, head->name) == 0)
    {
        popTail();
    }
    else
    {
        while (strcmpi(temp, curr->name) != 0)
        {
            curr = curr->next;
            if (!curr->next)
            {
                printf("No delete\n");
                break;
            }
        }
        curr->next->prev = curr->prev;
        curr->prev->next = curr->next;
        free(curr);
        curr = NULL;
    }
}

void popAll()
{
    while(head)
    {
        popHead();
    }
}

int main()
{
    pushMid(createNode("mika", 10));
    pushMid(createNode("gata", 15));
    pushMid(createNode("ozora", 20));
    pushMid(createNode("hans", 25));
    pushMid(createNode("geladis", 50));
    display();
    // popHead();
    // printf("\n");
    // display();
    // popTail();
    // printf("\n");
    // display();
    // popMid("hans");
    // printf("\n");
    // display();
    popAll();
    printf("\n");
    display();
}