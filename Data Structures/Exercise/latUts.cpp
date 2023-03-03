#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#define SIZE 20

struct Game{
	char name[100];
	char id[100];
	int rate;
	Game *next, *prev;
};

struct Table{
	Game *head, *tail;
} *table[SIZE];

void initTable(){
	for(int i = 0; i < SIZE; i++){
		table[i] = (Table *) malloc(sizeof(Table));
		table[i]->head = table[i]->tail = NULL;
	}
	return;
}

Game *createGame(const char *name, const char *id, int rate){
	Game *temp = (Game *) malloc(sizeof(Game));
	strcpy(temp->name, name);
	strcpy(temp->id, id);
	temp->rate = rate;
	temp->next = temp->prev = 0;
	return temp;
}

int hash(const char *name){
	int sum = 0;
	for(int i = 0; i < strlen(name); i++){
		sum += name[i];
	}
	return (sum % SIZE);
}

void view(){
	for(int i = 0; i < SIZE; i++){
		printf("%d. ", i);
		Game *curr = table[i]->head;
		while(curr){
			printf("%s -> ", curr->name);
			curr = curr->next;
		}
		printf("\n");
	}
}

void pushHead(int key, Game *newGame){
	if(!table[key]->head){
		table[key]->head = table[key]->tail = newGame;
	}else{
		newGame->next = table[key]->head;
		table[key]->head->prev = newGame;
		table[key]->head = newGame;
		return;
	}
}



void pushMid(int key, Game *newGame){
	Game* curr = table[key]->head;
	while(strcmpi(newGame->name, curr->next->name) > 0){
		curr = curr->next;
	}
	newGame->next = curr->next;
	newGame->prev = curr;
	curr->next->prev = newGame;
	curr->next = newGame;
}

void pushTail(int key, Game *newGame){
	if(!table[key]->tail){
		table[key]->head = table[key]->tail = newGame;
	}else{
		newGame->prev = table[key]->tail;
		table[key]->tail->next = newGame;
		table[key]->tail = newGame;
		return;
	}
}

void popHead(int key, char name[]){
	
	if(table[key]->head == table[key]->tail){
		free(table[key]);
		table[key]->head = table[key]->tail = NULL;
	}
	else if(strcmpi(table[key]->head->name, name) == 0){
		table[key]->head->next->prev = NULL;
		free(table[key]->head);
		table[key]->head = table[key]->head->next;	
	}
}

void popTail(int key, char name[]){
	
	if(table[key]->head == table[key]->tail){
		free(table[key]);
		table[key]->head = table[key]->tail = NULL;
	}
	else if(strcmpi(table[key]->tail->name, name) == 0){
		table[key]->tail->prev->next = NULL;
		free(table[key]->tail);
		table[key]->tail = 0;
		table[key]->tail = table[key]->tail->prev;	
	}
}

void popMid(int key, char name[]){
	Game* curr = table[key]->head;
	while(curr && strcmpi(curr->name, name) != 0){
		curr = curr->next;
	}
	curr->prev->next = curr->next;
	curr->next->prev = curr->prev;
	free(curr);
	curr=NULL;
//	Game *del = curr->next;
//	curr->next = del->next;
//	del->next->prev = curr;
//	free(del);
//	del = NULL;
}

void insertGame(Game *newGame){
	int key = hash(newGame->name);
	
	if(!table[key]->head || strcmpi(newGame->name, table[key]->head->name) < 0){
		pushHead(key, newGame);
	}else if(strcmpi(newGame->name, table[key]->tail->name) > 0){
		pushTail(key, newGame);
	}else {
		pushMid(key, newGame);
	}
}

void deleteGame(char name[]){
	int key = hash(name);
	
	if(strcmpi(name, table[key]->head->name) == 0){
		popHead(key, name);
	}else if(strcmpi(name, table[key]->tail->name) == 0){
		popTail(key, name);
	}else {
		popMid(key, name);
	}
}

int main(){
	initTable();
	
	insertGame(createGame("Mlaku-Mlaku", "345458", 34));
	insertGame(createGame("Uial", "345458", 34));
	insertGame(createGame("vfejjf", "35432", 34));
	insertGame(createGame("rumah", "35458", 34));
	insertGame(createGame("Mla", "3458", 34));
//	view();
//	printf("\n");
	
	deleteGame("Uial");
	
	view();
	
	return 0;
}
