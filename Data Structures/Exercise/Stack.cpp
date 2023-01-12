#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct data{
    char name[256];
    int age;

    struct data *next;
} *head = NULL;



void push(char const name[], int age){
    struct data *temp = (struct data *) malloc(sizeof(struct data));
    temp->age = age;
    temp->next = NULL;
    strcpy(temp->name, name);

    if(!head){
        head = temp;
    }else{
        temp->next = head;
        head = temp;
    }
}

void display(){
    struct data *curr = head;
    while(curr){
        printf("%s %d\n", curr->name, curr->age);
        curr = curr->next;
    }
}

void popHead(){
    if(!head){
        printf("stack is empty\n");
    }else{
        struct data *del = head;
        head = head->next;
        free(del);
    }
}

int main(){
    push("mika", 15);
    push("gata", 18);
    push("ozora", 25);
    display();
    printf("-----pop head--------\n");
    popHead();
    display();
}