#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int i = 0;

struct Student{
	char name[100];
	char nim[100];
	Student *left, *right;
} *root = NULL;

Student *createStd(const char *name, const char *nim){
	Student *temp = (Student *) malloc(sizeof(Student));
	strcpy(temp->name, name);
	strcpy(temp->nim, nim);
	temp->left = temp->right = NULL;
	return temp;
}

void view(Student *curr){
	if(!curr){
		return;
	}
	view(curr->left);
	printf("| %3d | %-15s | %-15s |\n", i, curr->name, curr->nim);
	i++;
	view(curr->right);
}

Student *insertStd(Student *curr, Student *newNode){
	if(!curr){
		return newNode;
	}else if(strcmpi(newNode->name, curr->name) < 0){
		curr->left = insertStd(curr->left, newNode);
	}else if(strcmpi(newNode->name, curr->name) > 0){
		curr->right = insertStd(curr->right, newNode);
	}
}

int searchStd(Student *curr, Student *newNode){
	if(!curr){
		return 0;
	}else if(strcmpi(newNode->name, curr->name) == 0){
		strcpy(curr->nim, newNode->nim);
		return 1;
	}else if(strcmpi(newNode->name, curr->name) < 0){
		searchStd(curr->left, newNode);
	}else if(strcmpi(newNode->name, curr->name) > 0){
		searchStd(curr->right, newNode);
	}
}

Student *deleteStd(Student *curr, const char *name){
	if(!curr){
		printf("Cannot delete because student name does not exist\n");
		return curr;
	}else if(strcmpi(name, curr->name) < 0){
		curr->left = deleteStd(curr->left, name);
	}else if(strcmpi(name, curr->name) > 0){
		curr->right = deleteStd(curr->right, name);
	}else{
		if(!curr->right && !curr->left){
			free(curr);
			curr = NULL;
		}else if(!curr->right){
			Student *del = curr;
			curr = curr->left;
			free(del);
			del = NULL;		
		}else if(!curr->left){
			Student *del = curr;
			curr = curr->right;
			free(del);
			del = NULL;	
		}else{
			Student *temp = curr->left;
			while(temp->right){
				temp = temp->right;
			}
			strcpy(curr->name, temp->name);
			strcpy(curr->nim, temp->nim);
			curr->left = deleteStd(curr->left, temp->name);
		}
	}
	return curr;
}

int checkNIM(const char *nim){
	int res = 1;
	if(strlen(nim) == 8){
		for(int i = 0; i < 8; i++){
			if(isdigit(nim[i]) == 0){
				return 0;
			}
		}
	}else{
		return 0;
	}
	return res;
}

void viewStd(){
	if(!root){
		printf("No data\n");
	}else{
		printf("=======================================\n");
		printf("| %3s | %-15s | %-15s |\n", "No", "Name", "NIM");
		printf("=======================================\n");
		view(root);
		printf("=======================================\n");
	}
}

void addStd(){
	char name[100] = {};
	char nim[100] = {};
	do{
		printf("Name: ");
		scanf("%[^\n]", name);
		getchar();
	}while(strlen(name) < 3 || strlen(name) > 50);
	do{
		printf("NIM: ");
		scanf("%[^\n]", nim);
		getchar();
	}while(checkNIM(nim) != 1);
	if(searchStd(root, createStd(name, nim)) == 1){
		printf("Student name already exists! updated NIM instead.\n");
		searchStd(root, createStd(name, nim));
	}else{
		root = insertStd(root, createStd(name, nim));
	}
	printf("Succes insert Student\n");
}

void remove(){
	char name[100] = {};
	
	viewStd();
	do{
		printf("Insert Name you want to delete: ");
		scanf("%[^\n]", name);
		getchar();
	}while(strlen(name) < 3 || strlen(name) > 50);
	root = deleteStd(root, name);
}

int main(){
	
//	root = insertStd(root, createStd("mika", "12345"));
//	root = insertStd(root, createStd("bijo", "12345"));
//	root = insertStd(root, createStd("Grace", "12345"));
//	root = insertStd(root, createStd("ryan", "12345"));
//	root = insertStd(root, createStd("marlin", "12345"));
//	searchStd(root, createStd("marlin", "23456"));
//	root = deleteStd(root, "awddaw");
//	view(root);

	int n;
	
	do{
		printf("Menu\n");
		printf("1. view\n");
		printf("2. Insert\n");
		printf("3. Delete\n");
		printf("4. Exit\n");
		printf(">> ");
		scanf("%d", &n);
		getchar();
		switch(n){
			case 1:
				i = 1;
				viewStd();
				break;
			case 2:
				addStd();
				break;
			case 3:
				i = 1;
				remove();
				break;
			case 4:
				break;
			default:
				break;	
		}
	}while(n != 4);
	
	return 0;
}
