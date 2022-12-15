#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *prev;
    struct node *next;
} *head = NULL, *tail = NULL;

struct node *newNode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = value;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

void insertTail(int value)
{
    struct node *temp = newNode(value);
    if (!head)
    { // first data
        head = tail = temp;
    }
    else
    {
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void displayAll()
{
    int i = 1;
    struct node *current = head;
    while (current)
    {
        printf("value %d: %d\n", i, current->value);
        current = current->next;
        i++;
    }
}

void deleteNode(int value)
{
    struct node *current = head;
    if(!head){
        return;
    }
    if (head->value == value && head == tail)
    { // only one data
        free(head);
        head = NULL;
        tail = NULL;
    }
    else if (head->value == value)
    { // delete head
        head = head->next;
        free(head->prev);
        head->prev = NULL;
    }
    else if (tail->value == value)
    {
        tail = tail->prev;
        free(tail->next);
        tail->next = NULL;
    }
    else
    { // delete in middle
        while (current->next->value != value)
        {
            current = current->next;
            if (!current->next)
            {
                break;
            }
        }
        if (current->next)
        {
            struct node *del = current->next;
            current->next = del->next;
            del->next->prev = current;
            free(del);
        }
    }
}

int main()
{
    insertTail(50);
    insertTail(54);
    insertTail(20);
    insertTail(34);
    insertTail(10);
    displayAll();
    printf("--------\n");
    deleteNode(50);
    deleteNode(54);
    deleteNode(20);
    deleteNode(34);
    deleteNode(10);
    deleteNode(1);
    displayAll();
}