#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//double linkedList

struct Node{
	char name[100];
	int age;
	Node *next, *prev;
};

Node *createNode(char *name, int age)
{
	Node *node = (Node*)malloc(sizeof(Node));
	strcpy(node->name, name);
	node->age = age;
	node->prev = node->next = NULL;
	
	return node;
}

void pushHead(Node **head, Node **tail, Node *node)
{
	if(!*head)
	{
		*head = *tail = node;
	}
	else{
		(*head)->prev= node;
		node->next=*head;
		*head=node;
	}
}

void pushTail(Node **head, Node **tail, Node *node)
{
	if(!*head)
	{
		*head = *tail = node;
	}
	else{
		(*tail)->next=node;
		node->prev=*tail;
		*tail=node;
	}
}

void pushValue(Node **head, Node **tail, Node *node)
{
	if(!*head || strcmp(node->name, (*head)->name)<0)
	{
		pushHead(head, tail, node);
	}
	else if(strcmp(node->name, (*tail)->name) >= 0)
	{
		pushTail(head, tail, node);
	}
	else
	{
		Node *curr = *head;
		while(strcmp(node->name, curr->next->name)>=0)
		{
			curr= curr->next;
		}
		
		//udah keluar dari while, tempel si node
		//a c
		// b
		//a->c
		//a<-c (diganti)
		//b->c
		//b<-c
		node->next=curr->next;
		curr->next->prev=node;
		node->prev = curr;
		curr->next = node;
	}
}

void view(Node *head)
{
	if(head==NULL)
	{
		printf("The data is empty\n");
	}
	
	Node *curr = head;
	while(curr)
	{
		printf("%s - %d\n", curr->name, curr->age);
		curr =curr->next;
	}
}

void popHead(Node **head, Node **tail)
{
	if(!*head) return;
	else if(*head==*tail)
	{
		free(*head);
		*head = *tail = NULL;
	}
	else
	{
		*head= (*head)->next;
		free((*head)->prev);
		(*head)->prev=NULL;
	}
}

void popTail(Node **head, Node **tail)
{
	if(!*head) return;
	else if(*head==*tail)
	{
		free(*head);
		*head = *tail = NULL;
	}
	else
	{
		*tail= (*tail)->prev;
		free((*tail)->next);
		(*tail)->next=NULL;
	}
}

void popValue(Node **head, Node **tail, char *name)
{
	if(!*head) return;
	else if(strcmp(name, (*head)->name) == 0)
	{
		popHead(head, tail);
	}
	else if(strcmp(name, (*tail)->name) == 0)
	{
		popTail(head, tail);
	}
	else
	{
		Node *curr = *head;
		while(curr->next != NULL && strcmp(curr->name, name)!= 0)
		{
			curr=curr->next;
		}
		
		if(curr->next == NULL)
		{
			printf("%s not found\n", name);
			return;
		}
		
		//delete
		//a b(curr) c
		
		curr->next->prev= curr->prev;
		curr->prev->next= curr->next;
		free(curr);
		curr= NULL;
	}
}

void popAll(Node **head, Node **tail)
{
	while(*head)
	{
		popHead(head, tail);
	}
}


int main()
{
	Node *head = NULL, *tail = NULL;
//	pushHead(&head, &tail, createNode("Erwin", 22));
//	pushTail(&head, &tail, createNode("Michael", 25));
//	pushTail(&head, &tail, createNode("anderson", 25));
	pushValue(&head, &tail, createNode("michael", 25));
	pushValue(&head, &tail, createNode("derwin", 25));
	pushValue(&head, &tail, createNode("franklin", 30));
	pushValue(&head, &tail, createNode("erwin", 30));
	pushValue(&head, &tail, createNode("josh", 30));
	
	view(head);
	printf("\n");
	
//	popHead(&head, &tail);
//	popTail(&head, &tail);
//	popValue(&head, &tail, "derwin");
//	popValue(&head, &tail, "erwin");
//	popValue(&head, &tail, "franklin");
	popAll(&head, &tail);
	
	view(head);
	return 0;
}
