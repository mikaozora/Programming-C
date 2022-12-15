#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
} *head = NULL;

struct node *newNode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

void insertNode(int value)
{
    struct node *temp = newNode(value);
    // insert first data
    if (head == NULL)
    {
        head = temp;
    }
    // insert second and more data
    else
    {
        temp->next = head;
        head = temp;
    }
}

void displayAll()
{
    int i = 1;
    struct node *current = head;
    while (current != NULL)
    {
        printf("value %d: %d\n", i, current->value);
        current = current->next;
        i++;
    }
}

void deleteNode(int value)
{
    struct node *current = head;

    if (value == current->value)
    { // value to delete in head
        head = current->next;
        free(current);
    }
    else
    { // value to delete in mid or last
        while (current->next->value != value)
        {
            current = current->next;
            if(current->next == NULL){
                break;
            }
        }
        
        if (current->next != NULL)
        {
        	struct node *del = current->next;
            current->next = del->next;
            free(del);
        }
    }
}


int main()
{
    insertNode(19);
    insertNode(29);
    insertNode(5);
    insertNode(75);
    insertNode(61);
    displayAll();
    printf("-------------\n");
    deleteNode(61);
    displayAll();
    printf("-------------\n");
    deleteNode(1);
    displayAll();
    return 0;
}
