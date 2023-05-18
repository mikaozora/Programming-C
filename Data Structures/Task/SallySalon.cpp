#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct Salon{
	char name[100];
	char category[100];
	int price;
	char service[100];
	Salon *left, *right;
	int height;
}*root = NULL;

Salon *createData(const char *name, const char *category, int price, const char *service){
	Salon *temp = (Salon*)malloc(sizeof(Salon));
	strcpy(temp->name, name);
	strcpy(temp->category, category);
	strcpy(temp->service, service);
	temp->price = price;
	temp->left = temp->right = NULL;
	temp->height = 1;
	return temp;
}

int max(int a, int b){
	return (a > b ? a: b);
}

int getHeight(Salon *curr){
	if(!curr){
		return 0;
	}
	return curr->height;
}

int getBf(Salon *curr){
	if(!curr){
		return 0;
	}
	return getHeight(curr->left) - getHeight(curr->right);
}

Salon *rightRotate(Salon *t){
	Salon *s = t->left;
	Salon *b = s->right;
	
	t->left = b;
	s->right = t;
	
	t->height = 1 + max(getHeight(t->left), getHeight(t->right));
	s->height = 1 + max(getHeight(s->left), getHeight(s->right));
	return s;
}

Salon *leftRotate(Salon *t){
	Salon *s = t->right;
	Salon *b = s->left;
	
	t->right = b;
	s->left = t;
	
	t->height = 1 + max(getHeight(t->left), getHeight(t->right));
	s->height = 1 + max(getHeight(s->left), getHeight(s->right));
	return s;
}

Salon *insertData(Salon *curr, Salon *newData){
	if(!curr){
		return newData;
	}else if(strcmp(newData->name, curr->name) < 0){
		curr->left = insertData(curr->left, newData);
	}else if(strcmp(newData->name, curr->name) > 0){
		curr->right = insertData(curr->right, newData);
	}else{
		return curr;
	}
	curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
	int bf = getBf(curr);
	
	if(bf > 1 && getBf(curr->left) >= 0){
		return rightRotate(curr);
	}
	if(bf < -1 && getBf(curr->right) <= 0){
		return leftRotate(curr);
	}
	if(bf > 1 && getBf(curr->left) < 0){
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	if(bf < -1 && getBf(curr->right) > 0){
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	return curr;
}

Salon *deleteData(Salon *curr, const char *name){
	if(!curr){
		printf("Data not found\n");
		printf("Press enter to continue..."); getchar();
		system("cls");
		return curr;
	}else if(strcmp(name, curr->name) < 0){
		curr->left = deleteData(curr->left, name);
	}else if(strcmp(name, curr->name) > 0){
		curr->right = deleteData(curr->right, name);
	}else{
		if(!curr->left && !curr->right){
			free(curr);
			curr = NULL;
			printf("\n[Delete Successfully]\n");
			printf("Press enter to continue..."); getchar();
			system("cls");
		}else if(!curr->right){
			Salon *del = curr;
			curr = curr->left;
			free(del);
			del = NULL;
			printf("\n[Delete Successfully]\n");
			printf("Press enter to continue..."); getchar();
			system("cls");
		}else if(!curr->left){
			Salon *del = curr;
			curr = curr->right;
			free(del);
			del = NULL;
			printf("\n[Delete Successfully]\n");
			printf("Press enter to continue..."); getchar();
			system("cls");
		}else{
			Salon *temp = curr->left;
			while(temp->right){
				temp = temp->right;
			}
			strcpy(curr->name, temp->name);
			strcpy(curr->category, temp->category);
			strcpy(curr->service, temp->service);
			curr->price = temp->price;
			curr->left = deleteData(curr->left, temp->name);
		}
		return curr;
	}
	curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
	int bf = getBf(curr);
	
	if(bf > 1 && getBf(curr->left) >= 0){
		return rightRotate(curr);
	}
	if(bf < -1 && getBf(curr->right) <= 0){
		return leftRotate(curr);
	}
	if(bf > 1 && getBf(curr->left) < 0){
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	if(bf < -1 && getBf(curr->right) > 0){
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	return curr;
}

void printHeader(){
	printf("======================================================================================================\n");
	printf("|| %-4s %10s %4s || %-3s %10s %3s || %-5s %5s %5s || %-6s %15s %6s ||\n", "", "Treatement", "", "", "Category", "", "", "Price", "", "", "Home Service", "");
	printf("======================================================================================================\n");
}
void printDetail(Salon *curr){
	printf("|| %-20s || %-18s || %-17d || %-29s ||\n", curr->name, curr->category, curr->price, curr->service);
}

void preDisplay(Salon *curr){
	if(!curr){
		return;
	}
	printDetail(curr);
	preDisplay(curr->left);
	preDisplay(curr->right);
}

void inDisplay(Salon *curr){
	if(!curr){
		return;
	}
	inDisplay(curr->left);
	printDetail(curr);
	inDisplay(curr->right);
}

void postDisplay(Salon *curr){
	if(!curr){
		return;
	}
	postDisplay(curr->left);
	postDisplay(curr->right);
	printDetail(curr);
}
int validateView(const char *choose){
	if(strcmp(choose, "pre") == 0){
		return 1;
	}else if(strcmp(choose, "in") == 0){
		return 2;
	}else if(strcmp(choose, "post") == 0){
		return 3;
	}
	return 0;
}

void viewProc(Salon *curr){
	char choose[100] = {};
	int res = 0;
	do{
		printf("input view order [pre | in | post]: ");
		scanf("%[^\n]", choose); getchar();
		res = validateView(choose);
	}while(res == 0);
	printHeader();
	if(res == 1){
		preDisplay(curr);
	}else if(res == 2){
		inDisplay(curr);
	}else if(res == 3){
		postDisplay(curr);
	}
	printf("===============================================================================================================\n");
}

int validateCategory(const char *category){
	if(strcmp(category, "Hair Care") == 0 || strcmp(category, "Nail Care") == 0 || strcmp(category, "Body Care") == 0){
		return 1;
	}
	return 0;
}

int validateService(const char *service){
	if(strcmp(service, "Available") == 0 || strcmp(service, "Unavailable") == 0){
		return 1;
	}
	return 0;
}

int validateName(const char *name){
	if(strlen(name) >= 5 && strlen(name) <= 20){
		if(name[0] == 'S' && name[1] =='a' && name[2] == 'l' && name[3] == 'l' && name[4] == 'y'){
			if(isspace(name[5]) != 0 && isalpha(name[6]) > 0){
				return 1;
			}
		}
	}
	return 0;
}

void addProc(){
	printf("INSERT NEW TREATMENT\n");
	char name[100] = {};
	int price = 0;
	char category[100] = {};
	char service[100] = {};
	do{
		printf("input new treatment name: ");
		scanf("%[^\n]", name); getchar();
	}while(validateName(name) == 0);
	do{
		printf("input treatement price [50000 - 1000000]: Rp");
		scanf("%d", &price); getchar();
	}while(price < 50000 || price > 1000000);
	do{
		printf("input treatment category [Hair Care | Nail Care | Body Care]: ");
		scanf("%[^\n]", category); getchar();
	}while(validateCategory(category) == 0);
	do{
		printf("input treatment category [Available | Unavailable]: ");
		scanf("%[^\n]", service); getchar();
	}while(validateService(service) == 0);
	root = insertData(root, createData(name, category, price, service));
	printf("\n[New Treatment is successfully inserted]\n");
	printf("Press enter to continue..."); getchar();
	system("cls");
}

void deleteProc(){
	char name[100] = {};
	printHeader();
	inDisplay(root);
	printf("======================================================================================================\n");
	printf("\nDELETE TREATMENT\n");
	printf("input treatment name to be deleted: ");
	scanf("%[^\n]", name); getchar();
	root = deleteData(root, name);
	
}

int main(){
	root = insertData(root, createData("Sally Manicure Plus", "Nail Care", 50000, "Available"));
	root = insertData(root, createData("Sally Hair Wash", "Hair Care", 50000, "Unavailable"));
	root = insertData(root, createData("Sally Blow Dry", "Hair Care", 50000, "Available"));
	root = insertData(root, createData("Sally Haircut", "Hair Care", 2500000, "Available"));
	root = insertData(root, createData("Sally Nail Extension", "Nail Care", 50000, "Available"));
	root = insertData(root, createData("Sally Oil Massage", "Body Care", 100000, "Available"));
	int n;
	do{
		printf("=== Sally Salon ===\n");
		printf("Menu:\n");
		printf("1. View Available Treatment\n2. Insert New Treatment\n3. Delete Treatment\n4. Exit\n[1-4]\n");
		printf(">> ");
		scanf("%d", &n); getchar();
		switch(n){
			case 1:
				if(root){
					viewProc(root);
				}else{
					printf("no data\n");
				}
				break;
			case 2:
				addProc();
				break;
			case 3:
				if(root){
				deleteProc();
				}else{
					printf("no data\n");
				}
				break;
			case 4:
				break;
			default:
				break;
		}
	}while(n != 4);
	return 0;
}
