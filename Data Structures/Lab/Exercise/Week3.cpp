#include <stdio.h>
#include <stdlib.h>

struct Food
{
    int price;
    struct Food *next;
} *head = NULL, *tail = NULL;

struct Food *createFood(int price)
{
    struct Food *food = (struct Food *)malloc(sizeof(struct Food));
    food->price = price;
    food->next = NULL;
}

void pushHead(int price){
    struct Food *newFood = createFood(price);
    if(!head){
        head = tail = newFood;
    }else{
        newFood->next = head;
        head = newFood;
    }
}

void printFoods(){
    struct Food *curr = head;
    while(curr){
        printf("%d\n", curr->price);
        curr = curr->next;
    }
}

void pushTail(int price){
    struct Food *newFood = createFood(price);
    if(!head){
        head = tail = newFood;
    }else{
        tail->next = newFood;
        tail = newFood;
    }
}

void pushMid(int price){
    if(!head || price < head->price){
        pushHead(price);
    }else if(price >= tail->price){
        pushTail(price);
    }else{
        struct Food *newFood = createFood(price);
        struct Food *curr = head;
        while(curr->next->price < price && curr->next != NULL){
            curr = curr->next;
        }
        newFood->next = curr->next;
        curr->next = newFood;
    }
}

void popHead(){
    if(!head){
        return;
    }else if(head == tail){
        free(head);
        head = tail = NULL;
    }else{
        struct Food *temp = head->next;
        free(head);
        head = temp;
    }
}

void popTail(){
    if(!head){
        return;
    }else if(head == tail){
        free(head);
        head = tail = NULL;
    }else{
        struct Food *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        free(tail);
        temp->next = NULL;
        tail = temp;
    }
}

int main()
{
    int arr[100] = {1, 2, 3};

    // struct Food *food = createFood(20000);
    pushMid(1000);
    pushMid(2000);
    pushMid(3000);
    pushMid(2500);
    pushMid(2501);
    popHead();
    popTail();
    // printf("%d\n", head->next->price);
    printFoods();
}