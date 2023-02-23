#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 1007
int count = 0;
int bookCount = 0;

struct Book{
	char id[100];
	char title[100];
	char author[100];
	char ISBN[25];
	int page;
	Book *next, *prev;
};

struct Table{
	Book *head, *tail;
} *table[SIZE];

void initTable(){
	for(int i = 0; i < SIZE; i++){
		table[i] = (Table *) malloc(sizeof(Table));
		table[i]->head = table[i]->tail = NULL;
	}
	return;
}

Book *createBook(const char *id, const char *title, const char *author, const char *ISBN, int page){
	Book *temp = (Book *) malloc(sizeof(Book));
	strcpy(temp->title, title);
	strcpy(temp->id, id);
	strcpy(temp->author, author);
	strcpy(temp->ISBN, ISBN);
	temp->page = page;
	temp->next = temp->prev = NULL;
	return temp;
}

void view(){
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %-35s | %-35s | %-30s | %-25s | %-25s |\n", "Book ID", "Book Title", "Book Author", "ISBN", "Page Number");
	printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
	for(int i = 0; i < SIZE; i++){
		Book *curr = table[i]->head;
		while(curr){
			printf("| %-35s | %-35s | %-30s | %-25s | %-25d |\n", curr->id, curr->title, curr->author, curr->ISBN, curr->page);
			printf("-----------------------------------------------------------------------------------------------------------------------------------------------------\n");
			curr = curr->next;
		}
	}
	printf("Press Enter to continue..."); getchar();
	return;
}

int hash(const char *id){
	int sum = 0;
	for(int i = 0; i < strlen(id); i++){
		sum += id[i];
	}
	return (sum % SIZE);
}

void pushHead(Book *newBook, int key){
	if(!table[key]->head){
		table[key]->head = table[key]->tail = newBook;
	}else{
		newBook->next = table[key]->head;
		table[key]->head->prev = newBook;
		table[key]->head = newBook;
	}
}

void pushTail(Book *newBook, int key){
	if(!table[key]->tail){
		table[key]->head = table[key]->tail = newBook;
	}else{
		table[key]->tail->next = newBook;
		newBook->prev = table[key]->tail;
		table[key]->tail = newBook;
	}
}

void pushMid(Book *newBook, int key){
	Book *curr = table[key]->head;
	while(curr && strcmpi(newBook->id, curr->next->id) > 0){
		curr = curr->next;
	}
	newBook->next = curr->next;
	curr->next->prev = newBook;
	curr->next = newBook;
	newBook->prev = curr;
}

void insertBook(Book *newBook){
	int key = hash(newBook->id);
//  priority queue
//	if(!table[key]->head || strcmpi(newBook->id, table[key]->head->id) < 0){
//		pushHead(newBook, key);
//	}else if(strcmpi(newBook->id, table[key]->tail->id) > 0){
//		pushTail(newBook, key);
//	}else{
//		pushMid(newBook, key);
//	}

	pushTail(newBook, key);
	return;
}

void popHead(const char *id, int key){
	if(table[key]->head == table[key]->tail){
		free(table[key]->head);
		table[key]->head = table[key]->tail = NULL;
	}else{
		Book *del = table[key]->head;
		table[key]->head = del->next;
		table[key]->head->prev = NULL;
		free(del);
		del = NULL;
	}
}

void popTail(const char *id, int key){
	if(table[key]->head == table[key]->tail){
		free(table[key]->tail);
		table[key]->head = table[key]->tail = NULL;
	}else{
		Book *del = table[key]->tail;
		table[key]->tail = del->prev;
		table[key]->tail->next = NULL;
		del = NULL;
	}
}

void popMid(const char *id, int key){
	Book *curr = table[key]->head;
	while(curr && strcmpi(id, curr->next->id) != 0){
		curr = curr->next;
	}
	if(!curr){
		printf("No data\n");
		return;
	}
	Book *del = curr->next;
	curr->next = del->next;
	del->next->prev = curr;
	free(del);
	del = NULL;
}

void deleteBook(const char *id){
	int key = hash(id);
	if(!table[key]){
		return;
	}else if(strcmpi(id, table[key]->head->id) == 0){
		popHead(id, key);
	}else if(strcmpi(id, table[key]->tail->id) == 0){
		popTail(id, key);
	}else{
		popMid(id, key);
	}
}

int searchTitle(const char *title){
	for(int i = 0; i < SIZE; i++){
		Book *curr = table[i]->head;
		if(!curr){
//			printf("kontinu\n");
			continue;
		}else{
			while(curr && strcmpi(title, curr->title) != 0){
				curr = curr->next;
			}
			if(!curr){
				continue;
			}
			return 1;
		}
	}
	return 0;
}

int validateAuthor(const char *author){
	if(author[0] == 'M' && author[1] == 'r' && author[2] == '.' && author[3] == ' '){
		if(strlen(author) >= 7 && strlen(author) <= 29){
			return 1;
		}else{
			return 0;
		}		
	}else if(author[0] == 'M' && author[1] == 'r' && author[2] == 's' && author[3] == '.' && author[4] == ' '){
		if(strlen(author) >= 7 && strlen(author) <= 29){
			return 2;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

int validateISBN(const char *isbn){
	if(strlen(isbn) >= 10 && strlen(isbn) <= 13){
		for(int i = 0; i < strlen(isbn); i++){
			if(isdigit(isbn[i]) == 0){
				return 0;
			}
		}
	}else{
		 return 0;
	}
	return 1;
}

void detailId(const char *id){
	char choose[100] = {};
	int key = hash(id);
	printf("\n\n\n");
	Book *curr = table[key]->head;
	while(curr && strcmp(id, curr->id) != 0){
		curr = curr->next;
	}
	if(!curr){
		printf("Book not found!\n");
		return;
	}
	printf("Book Id: %s\n", curr->id);
	printf("Book Title: %s\n", curr->title);
	printf("Book Author: %s\n", curr->author);
	printf("Book ISBN: %s\n", curr->ISBN);
	printf("Page Number: %d\n", curr->page);
	do{
		printf("Are you sure [y|n]? ");
		scanf("%[^\n]", choose); getchar();
	}while(strcmp(choose, "y") != 0 && strcmp(choose, "n") != 0);
	if(strcmp(choose, "y") == 0){
		deleteBook(id);
		bookCount--;
		printf("\nDelete success!\n");
	}else{
		return;
	}
	return;
}

char *generateId(const char *author, const char *title, const char *isbn){
	char temp[100]= {};
	char firstAuthor;
	count++;
	if(validateAuthor(author) == 1){
		firstAuthor = author[4];
	}else if(validateAuthor(author) == 2){
		firstAuthor = author[5];
	}
	sprintf(temp, "B%05d-%s-%c%c", count, isbn, toupper(firstAuthor) , toupper(title[0]));
	printf("%s\n", temp);
	return temp;
}

void viewAll(){
	if(bookCount == 0){
		printf("There is no book(s)!\n\n");
		printf("Press Enter to Continue...");
		getchar();
		system("cls");
	}else{
		view();
	}
}

void procAdd(){
	char title[100] = {};
	char author[100] = {};
	char id[100] = {};
	char ISBN[100] = {};
	int page = 0;
	do{
		printf("Input book title[5-50][unique]: ");
		scanf("%[^\n]", title); getchar();
		if(searchTitle(title) == 1){
			printf("The book title is already exists!\n");
		}
	}while(strlen(title) < 5 || strlen(title) > 50 || searchTitle(title) == 1);
	do{
		printf("Input author name[3-25][Mr. ][Mrs. ]: ");
		scanf("%[^\n]", author); getchar();
//		printf("%d\n", validateAuthor(author));
	}while(validateAuthor(author) == 0);
	do{
		printf("Input ISBN[10-13][numeric]: ");
		scanf("%[^\n]", ISBN); getchar();
	}while(validateISBN(ISBN) == 0);
	do{
		printf("Input page number[>= 16]: ");
		scanf("%d", &page); getchar();
	}while(page < 16);
	strcpy(id, generateId(author, title, ISBN));
	insertBook(createBook(id, title, author, ISBN, page));
	printf("Insert Success !\n");
	bookCount++;
}

void procDelete(){
	char id[100] = {};
	printf("Input book id to delete: ");
	scanf("%[^\n]", id); getchar();
	detailId(id);
}

int main(){
	initTable();
//	insertBook(createBook("1234567", "buku keren", "adawdadw", "2345", 17));
//	insertBook(createBook("1234568", "Aaaa keren", "adawdadw", "2345", 17));
//	insertBook(createBook("1234569", "da keren", "adawdadw", "2345", 17));
//	insertBook(createBook("1234565", "dwdw keren", "adawdadw", "2345", 17));
//	insertBook(createBook("2345667", "dfgre keren", "adawdadw", "2345", 17));
//	printf("%d", searchTitle("da keren"));
//	view();
//	deleteBook("12345670999");
	
	int n;
	do{
		printf("Bluejack Library\n");
		printf("==================\n");
		printf("1. View\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &n);
		getchar();
		switch(n){
			case 1:
				viewAll();
				break;
			case 2:
				procAdd();
				break;
			case 3:
				procDelete();
				break;
			case 4:
				break;
			default:
				break;
		}
	}while(n != 4);
	return 0;
}
