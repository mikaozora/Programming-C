#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    char name[256];
    int age;

    struct data *next;
} *head = NULL, *tail = NULL;

void push(char const name[], int age)
{
    struct data *temp = (struct data *)malloc(sizeof(struct data));
    temp->age = age;
    temp->next = NULL;
    strcpy(temp->name, name);

    if (!tail)
    {
        tail = head = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void display()
{
    struct data *curr = head;
    while (curr)
    {
        printf("%s %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

void pop()
{
    struct data *curr = head;
    if (!tail)
    {
        printf("No queue\n");
    }
    else
    {
        struct data *del = head;
        head = head->next;
        free(del);
    }
}

int main()
{
    push("mika", 10);
    push("gata", 30);
    push("ozora", 25);
    display();
    printf("\n");
    pop();
    display();
}