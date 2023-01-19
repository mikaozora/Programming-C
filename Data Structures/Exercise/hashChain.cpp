#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxArrSize = 20;

struct data{
    char heroName[20];
    char heroType[5];
    int lvl;

    struct data *next;
} *dataArr[maxArrSize];

int hashFunc(char heroName[]){
    char first = heroName[0];
    char last = heroName[strlen(heroName) - 1];

    int res = (first + last) % maxArrSize;
    return res;

}

void insert(char const heroName[], char const heroType[], int lvl){
    struct data *temp = (struct data *) malloc(sizeof(struct data));
    strcpy(temp->heroName, heroName);
    strcpy(temp->heroType, heroType);
    temp->lvl = lvl;
    temp->next = NULL;

    int index = hashFunc(temp->heroName);
    // printf("%d\n", index);

    if(!dataArr[index]){
        dataArr[index] = temp;
    }else{
        struct data *curr = dataArr[index];
        while(curr->next){
            curr = curr->next;
        }
        curr->next = temp;
    }

}

void display(){
    for(int i = 0; i < maxArrSize; i++){
        if(dataArr[i]){
            struct data *curr = dataArr[i];
            while(curr){
                printf("%s %s %d -> ", curr->heroName, curr->heroType, curr->lvl);
                curr = curr->next;
            }
            printf("\n");
        }
    }
}

int main(){
    insert("invoker", "asg", 1);
    insert("invor", "asg", 1);
    insert("axe", "str", 1);
    display();
}