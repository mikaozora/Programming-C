#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// priority queue

struct data
{
    char name[256];
    char NIM[10];
    float gpa;

    struct data *next;
} *head = NULL, *tail = NULL;

void pushDesc(char const name[], char const NIM[], float gpa)
{
    // priority based on gpa desc

    struct data *temp = (struct data *)malloc(sizeof(struct data));
    strcpy(temp->name, name);
    strcpy(temp->NIM, NIM);
    temp->gpa = gpa;
    temp->next = NULL;
    if (!head)
    {
        head = tail = temp;
    }
    else if (temp->gpa > head->gpa)
    {
        temp->next = head;
        head = temp;
    }
    else if (temp->gpa <= tail->gpa)
    {
        tail->next = temp;
        tail = temp;
    }
    else
    {
        struct data *curr = head;
        while (curr->next->gpa >= temp->gpa)
        {
            curr = curr->next;
            if (!curr->next)
            {
                break;
            }
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}
void pushDescName(char const name[], char const NIM[], float gpa)
{
    // priority based on gpa desc

    struct data *temp = (struct data *)malloc(sizeof(struct data));
    strcpy(temp->name, name);
    strcpy(temp->NIM, NIM);
    temp->gpa = gpa;
    temp->next = NULL;
    if (!head)
    {
        head = tail = temp;
    }
    else if (strcmpi(temp->name, head->name) > 0)
    {
        temp->next = head;
        head = temp;
    }
    else if (strcmpi(temp->name, tail->name) <= 0)
    {
        tail->next = temp;
        tail = temp;
    }
    else
    {
        struct data *curr = head;
        while (strcmpi(curr->next->name, temp->name) >= 0)
        {
            curr = curr->next;
            if (!curr->next)
            {
                break;
            }
        }
        temp->next = curr->next;
        curr->next = temp;
    }
}

void pop()
{
    struct data *del = head;
    if (!head)
    {
        printf("No Queue\n");
    }
    else
    {
        head = head->next;
        free(del);
    }
}

void display()
{
    struct data *curr = head;
    while (curr)
    {
        printf("%s %s %.2f\n", curr->name, curr->NIM, curr->gpa);
        curr = curr->next;
    }
}

int main()
{
    pushDescName("Dika", "123", 4.5);
    pushDescName("data", "124", 4.1);
    pushDescName("aoll", "125", 5);
    pushDescName("zezi", "126", 4.2);
    display();
    printf("\n");
    pop();
    display();
}