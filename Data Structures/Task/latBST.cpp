#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student{
	char name[100];
	float gpa;
	Student *left, *right;
}*root = NULL;

Student *createStudent (const char *name, float gpa){
	Student *newStudent = (Student *) malloc(sizeof(Student));
	strcpy(newStudent->name, name);
	newStudent->gpa = gpa;
	newStudent->right = newStudent->left = NULL;
	return newStudent;
}

Student *insertStd(Student *curr, Student *newStd){
	if(!curr){
		return newStd;
	}else if(strcmpi(newStd->name, curr->name) < 0){
		curr->left = insertStd(curr->left, newStd);
	}else if(strcmpi(newStd->name, curr->name) > 0){
		curr->right = insertStd(curr->right, newStd);
	}
	return curr;
}

Student *deleteStd(Student *curr, const char name[100]){
	if(!curr){
		printf("data not found\n");
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
			Student *temp = curr;
			curr = curr->left;
			free(temp);
			temp = NULL;
		}else if(!curr->left){
			Student *temp = curr;
			curr = curr->right;
			free(temp);
			temp = NULL;
		}else{
			//right most left child
			Student *temp = curr->left;
			while(temp->right){
				temp = temp->right;
			}
			strcpy(curr->name, temp->name);
			curr->gpa = temp->gpa;
			curr->left = deleteStd(curr->left, temp->name);	
		}
	}
	return curr;
}

void updateGpa(const char *name, float gpa, Student *curr){
	if(!curr){
		printf("No data\n");
		return;
	}else if(strcmpi(name, curr->name) == 0){
		curr->gpa = gpa;
		return;
	}else if(strcmpi(name, curr->name) < 0){
		updateGpa(name, gpa, curr->left);
		return;
	}else if(strcmpi(name, curr->name) > 0){
		updateGpa(name, gpa, curr->right);
		return;
	}
}

int searchStd(Student *curr, const char *name){
	if(!curr){
		printf("Data Not Found\n");
		return 0;
	}else if(strcmpi(name, curr->name) == 0){
		printf("Data Found\n");
		return 1;
	}else if(strcmpi(name, curr->name) < 0){
		searchStd(curr->left, name);
	}else if(strcmpi(name, curr->name) > 0){
		searchStd(curr->right, name);
	}
}

void inTraversal(Student *curr){
	if(!root){
		printf("Please insert data\n");
	}
	if(!curr){
		return;
	}
	inTraversal(curr->left);
	printf("%s %.2f\n", curr->name, curr->gpa);
	inTraversal(curr->right);
}

int main(){
	root = insertStd(root, createStudent("mika", 3.5));
	root = insertStd(root, createStudent("gladis", 3.7));
	root = insertStd(root, createStudent("apeng", 3.6));
	root = insertStd(root, createStudent("athalia", 3.6));
	root = insertStd(root, createStudent("delvin", 3.6));
	root = insertStd(root, createStudent("stefi", 3.6));
	root = insertStd(root, createStudent("stephen", 3.6));
	root = insertStd(root, createStudent("ruth", 3.6));
	inTraversal(root);
	printf("============\n");
	root = deleteStd(root, "stephen");
	inTraversal(root);
	printf("============\n");
	updateGpa("delvin", 4.5, root);
	inTraversal(root);
	searchStd(root, "stefi");
	return 0;
}
