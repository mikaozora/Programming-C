#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Food{
	char name[100];
	int price;
	Food *next;
} *head = NULL, *tail = NULL;

Food *createFood(const char *name, int price){
	Food *temp = (Food *) malloc(sizeof(Food));
	strcpy(temp->name, name);
	temp->price = price;
	temp->next = NULL;
	return temp;
}

void view(){
	Food *curr = head;
	while(curr){
		printf("%s %d\n", curr->name, curr->price);
		curr = curr->next;
	}
}

void pushHeadPrice(int price, const char *name){
	Food *newFood = createFood(name, price);
	if(!head){
		head = tail = newFood;
	}else{
		newFood->next = head;
		head = newFood;
	}
}

void pushTailPrice(int price, const char *name){
	Food *newFood = createFood(name, price);
	if(!tail){
		head = tail = newFood;
	}else{
		tail->next = newFood;
		tail = newFood;
	}
}

void priorityByPrice(int price, const char *name){
	if(!head || price < head->price){
		pushHeadPrice(price, name);
	}else if(price > tail->price){
		pushTailPrice(price, name);
	}else{
		Food *newFood = createFood(name, price);
		Food *curr = head;
		while(curr && curr->next->price < newFood->price){
			curr = curr->next;
		}
		newFood->next = curr->next;
		curr->next = newFood;
	}
}

void popHeadPrice(int price){
	if(!head){
		return;
	}else if(head == tail){
		free(head);
		head = NULL;
	}else{
		Food *del = head;
		head = head->next;
		free(del);
		del = NULL;
	}
}

void popTailPrice(int price){
	if(!tail){
		return;
	}else if(tail == head){
		free(tail);
		tail = NULL;
	}else{
		Food *curr = head;
		while(curr->next != tail){
			curr = curr->next;
		}
		free(tail);
		curr->next = NULL;
		tail = curr;
	}
}

void popByPrice(int price){
//	Food *curr = head;
	if(!head || price == head->price){
		popHeadPrice(price);
	}else if(price == tail->price){
		popTailPrice(price);
	}else{
		Food *curr = head;
		while(curr && curr->next->price != price){
			curr = curr->next;
		}
		if(!curr){
			printf("data not found\n");
			return;
		}
		Food *del = curr->next;
		curr->next = curr->next->next;
		free(del);
		del = NULL;
	}
}

void pushHeadName(int price, const char *name){
	Food *newFood = createFood(name, price);
	if(!head){
		head = tail = newFood;
	}else{
		newFood->next = head;
		head = newFood;
	}
}

void pushTailName(int price, const char *name){
	Food *newFood = createFood(name, price);
	if(!tail){
		head = tail = newFood;
	}else{
		tail->next = newFood;
		tail = newFood;
	}
}

void priorityByName(int price, const char *name){
	if(!head || strcmpi(name, head->name) < 0){
		pushHeadName(price, name);
	}else if(strcmpi(name, tail->name) > 0){
		pushTailName(price, name);
	}else{
		Food *curr = head;
		Food *newFood = createFood(name, price);
		while(curr && strcmpi(curr->next->name, name) < 0){
			curr = curr->next;
		}
		newFood->next = curr->next;
		curr->next = newFood;
	}
}

void popHeadName(const char *name){
	if(!head){
		return;
	}else if(head == tail){
		free(head);
		head = tail = NULL;
	}else{
		Food *del = head;
		head = head->next;
		free(del);
		del = NULL;
	}
}

void popTailName(const char *name){
	if(!tail){
		return;
	}else if(head == tail){
		free(tail);
		tail = head = NULL;
	}else{
		Food *curr = head;
		while(curr && strcmpi(curr->next->name, tail->name) != 0){
			curr = curr->next;
		}
		curr->next = NULL;
		free(tail);
		tail = curr;
	}
}

void popByName(const char *name){
	if(strcmpi(name, head->name) == 0){
		popHeadName(name);
	}else if(strcmpi(name, tail->name) == 0){
		popTailName(name);
	}else{
		Food *curr = head;
		while(curr && strcmpi(curr->next->name, name) != 0){
			curr = curr->next;
		}
		if(!curr){
			printf("Data not found\n");
			return;
		}
		Food *del = curr->next;
		curr->next = del->next;
		free(del);
		del = NULL;
	}
}

int main(){
	priorityByName(10000, "Sate padang");
	priorityByName(15000, "Sate madura");
	priorityByName(2000, "baso padang");
	priorityByName(5000, "nasi goreng");
	priorityByName(7800, "fetucini");
	priorityByName(1000000, "cordon bleu");
	view();
	printf("=============\n");
	popByName("fetucini");
	popByName("baso padang");
	popByName("sAte haram");
	view();
	return 0;
}
