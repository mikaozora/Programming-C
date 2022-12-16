#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
} *head = NULL, *tail = NULL;

struct node *newNode(int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->value = value;
    return temp;
}

void insertHead(int value)
{
    struct node *temp = newNode(value);

    if (!head)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
}
void insertTail(int value)
{
    struct node *temp = newNode(value);

    if (!tail)
    {
        tail = temp;
        head = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void insertMiddleAsc(int value)
{
    struct node *current = head;
    struct node *temp = newNode(value);

    // asc
    while (current->next->value < value)
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;

}
void insertMiddleDesc(int value)
{
    
    struct node *current = head;
    struct node *temp = newNode(value);

    // desc
    while (current->next->value > value)
    {
        current = current->next;
    }
    temp->next = current->next;
    current->next = temp;
}

void displayAll()
{
    struct node *current = head;
    while (current)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void insertDataAsc(int value){

    if(!head){
        insertHead(value);
        // insertTail(value);
    }else if(value < head->value){
        insertHead(value);
    }else if(value > tail->value){
        insertTail(value);
    }else{
        insertMiddleAsc(value);
    }
}

void insertDataDesc(int value){
    if(!head){
        insertHead(value);
        // insertTail(value);
    }else if(value > head->value){
        insertHead(value);
    }else if(value < tail->value){
        insertTail(value);
    }else{
        insertMiddleDesc(value);
    }
}

int main()
{
    // insertTail(30);
    // insertTail(20);
    // insertTail(10);
    // insertMiddleDesc(25);
    // insertMiddleDesc(15);
    insertDataDesc(10);
    insertDataDesc(40);
    insertDataDesc(30);
    insertDataDesc(20);
    displayAll();
}