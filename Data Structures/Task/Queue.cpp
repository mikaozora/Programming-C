#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
	int value;
	Node *next;
} *head = NULL, *tail = NULL;

Node *createNode(int value){
	Node *temp = (Node *) malloc(sizeof(Node));
	temp->value = value;
	temp->next = NULL;
	return temp;
}

void view(){
	Node *curr = head;
	while(curr){
		printf("%d ", curr->value);
		curr = curr->next;
	}
}

void insertQueue(int value){
	Node *newNode = createNode(value);
	if(!tail){
		tail = head = newNode;
	}else{
		tail->next = newNode;
		tail = newNode;
	}
}

void pop(){
	// queue pop always from head because FIFO (First in First Out)
	if(!tail){
		printf("No data\n");
		return;
	}else{
		Node *del = head;
		head = head->next;
		free(del);
		del = NULL;
	}
}

int main(){
	insertQueue(20);
	insertQueue(60);
	insertQueue(50);
	view();
	pop();
	printf("\n");
	view();
	return 0;
}
