#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	char name[100];
	char type[100];
	Node *next;
} *head = NULL, *tail = NULL;

Node *createNode(const char *name, const char *type){
	Node *temp = (Node *) malloc(sizeof(Node));
	strcpy(temp->name, name);
	strcpy(temp->type, type);
	temp->next = NULL;
	return temp;
}

void pushHead(const char *name, const char *type){
	Node *newNode = createNode(name, type);
	if(!head){
		head = tail = newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(const char *name, const char *type){
	Node *newNode = createNode(name, type);
	if(!tail){
		head = tail = newNode;
	}else{
		tail->next = newNode;
		tail = newNode;
	}
}

void pushMid(const char *name, const char *type){
	Node *curr = head;
	while(curr && strcmpi(curr->next->name, name) < 0){
		curr = curr->next;
	}
	Node *newNode = createNode(name, type);
	newNode->next = curr->next;
	curr->next = newNode;
}

void insertNode(const char *name, const char *type){
	if(!head || strcmpi(name, head->name) < 0){
		pushHead(name, type);
	}else if(strcmpi(name, tail->name) > 0){
		pushTail(name, type);
	}else{
		pushMid(name, type);
	}
}

void view(){
	Node *curr = head;
	while(curr){
		printf("%s %s\n", curr->name, curr->type);
		curr = curr->next;
	}
}

void importData(){
	FILE *file;
	file = fopen("test.in", "r");
	char name[100] = {};
	char type[100] = {};
	while(!feof(file)){
//		printf("testbr");
		fscanf(file, "%[^#]#%[^\n]\n", name, type);
		insertNode(name, type);
	}
}


int main(){
	importData();
	view();
	return 0;
}
