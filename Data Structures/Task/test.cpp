#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 26

struct Std{
	char name[100];
	Std *next, *prev;
};

struct Table{
	Std *head, *tail;
} *table[SIZE];

void initTable(){
	for(int i = 0; i < SIZE; i++){
		table[i] = (Table *) malloc(sizeof(Table));
		table[i]->head = table[i]->tail = NULL;
	}
	return;
}

Std *createStd(const char *name){
	Std *temp = (Std *) malloc(sizeof(Std));
	strcpy(temp->name, name);
	temp->next = temp->prev = NULL;
	return temp;
}

void view(){
	for(int i = 0; i < SIZE; i++){
		printf("%d. ", i);
		Std *curr = table[i]->head;
		while(curr){
			printf("%s, ", curr->name);
			curr = curr->next;
		}
		printf("\n");
	}
}

int hash(const char *name){
	if(name[0] >= 'A' && name[0] <= 'Z'){
		return (name[0] - 'A') % SIZE;
	}else if(name[0] >= 'a' && name[0] <= 'z'){
		return (name[0] - 'a') % SIZE;
	}
	return name[0] % SIZE;
}

void pushHead(const char *name, int key){
	if(!table[key]->head){
		table[key]->head = table[key]->tail = createStd(name);
	}else{
		Std *newStd = createStd(name);
		newStd->next = table[key]->head;
		table[key]->head->prev = newStd;
		table[key]->head = newStd;
	}
}

void pushTail(const char *name, int key){
	if(!table[key]->tail){
		table[key]->head = table[key]->tail = createStd(name);
	}else{
		Std *newStd = createStd(name);
		table[key]->tail->next = newStd;
		newStd->prev = table[key]->tail;
		table[key]->tail = newStd;
	}
}

void pushMid(const char *name, int key){
	Std *curr = table[key]->head;
	while(curr && strcmpi(name, curr->next->name) > 0){
		curr = curr->next;
	}
	Std *newStd = createStd(name);
	newStd->next = curr->next;
	curr->next = newStd;
	newStd->prev = curr;
	newStd->next->prev = newStd;
	return;
}

void insertStd(const char *name){
	int key = hash(name);
	if(!table[key] || strcmpi(name, table[key]->head->name) < 0){
		pushHead(name, key);
	}else if(strcmpi(name, table[key]->tail->name) > 0){
		pushTail(name, key);
	}else{
		pushMid(name, key);
	}
	return;
}

void popHead(const char *name, int key){
	if(table[key]->head == table[key]->tail){
		free(table[key]->head);
		table[key]->head = table[key]->tail = NULL;
	}else{
		Std *newHead = table[key]->head->next;
		newHead->prev = NULL;
		free(table[key]->head);
		table[key]->head = newHead;
	}
}

void popTail(const char *name, int key){
	if(table[key]->head == table[key]->tail){
		free(table[key]->tail);
		table[key]->head = table[key]->tail = NULL;
	}else{
		Std *newTail = table[key]->tail->prev;
		newTail->next = NULL;
		free(table[key]->tail);
		table[key]->tail = newTail;
	}
}

void popMid(const char *name, int key){
	Std *curr = table[key]->head;
	while(curr && strcmpi(name, curr->next->name) != 0){
		curr = curr->next;
	}
	if(!curr){
		printf("Data not found\n");
		return;
	}
	Std *del = curr->next;
	curr->next = del->next;
	del->next->prev = curr;
	free(del);
	del = NULL;
	return;
}

void deleteStd(const char *name){
	int key = hash(name);
	if(!table[key]){
		return;
	}else if(strcmpi(name, table[key]->head->name) == 0){
		popHead(name, key);
	}else if(strcmpi(name, table[key]->tail->name) == 0){
		popTail(name, key);
	}else{
		popMid(name, key);
	}
	return;
}

void searchStd(const char *name){
	int key = hash(name);
	Std *curr = table[key]->head;
	while(curr){
		if(strcmpi(name, curr->name) == 0){
			printf("data found\n");
			return;
		}
		curr = curr->next;
	}
	if(!curr){
		printf("data not found\n");
	}
}

int main(){
	initTable();
	insertStd("mika");
	insertStd("abdi");
	insertStd("gladis");
	insertStd("delvin");
	insertStd("stefi");
	insertStd("kurniyasa");
	insertStd("apeng");
	insertStd("atha");
	insertStd("shamgar");
	deleteStd("gladis");
	view();
//	searchStd("delvin"); bug
	return 0;
}
