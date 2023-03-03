#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

struct Std{
	char name[100];
	char id[100];
	int assets;
	int equity;
	int liabilities;
	Std *left, *right;
} *root = NULL;

Std *createStd(const char *name, const char *id, int equity, int lia){
	Std *temp = (Std *)malloc(sizeof(Std));
	strcpy(temp->name, name);
	strcpy(temp->id, id);
	temp->assets = equity+lia;
	temp->equity = equity;
	temp->liabilities = lia;
	temp->left = temp->right = NULL;
	return temp;
}

void view(Std *curr){
	if(!curr){
		return;
	}
	view(curr->left);
	printf("%s - %s\n", curr->name, curr->id);
	view(curr->right);
}

char *generateId(const char name[100]){
	char temp[100] = {};
	srand(time(NULL));
	int num = (rand() % (99999 - 10000 + 1)) + 10000;
	sprintf(temp, "ST-%d-%c%c", num, toUpper(name[0]), toupper(name[strlen(name)-1]));
	return temp;
}

Std *insertStd(Std *curr, Std *newStd){
	if(!curr){
		return newStd;
	}else if(strcmp(newStd->id, curr->id) < 0){
		curr->left = insertStd(curr->left, newStd);
	}else if(strcmp(newStd->id, curr->id) > 0){
		curr->right = insertStd(curr->right, newStd);
	}
}

Std *deleteStd(Std *curr, const char *id){
	if(!curr){
		return curr;
	}else if(strcmp(id, curr->id) < 0){
		curr->left = deleteStd(curr->left, id);
	}else if(strcmp(id, curr->id) > 0){
		curr->right = deleteStd(curr->right, id);
	}else{
		if(!curr->left && !curr->right){
			free(curr);
			curr = NULL;
		}else if(!curr->right){
			Std *del = curr;
			curr = curr->left;
			free(del);
			del = NULL;
		}else if(!curr->left){
			Std *del = curr;
			curr = curr->right;
			free(del);
			del = NULL;
		}else{
			Std *temp = curr->left;
			while(temp->right){
				temp = temp->right;
			}
			strcpy(curr->name, temp->name);
			strcpy(curr->id, temp->id);
			curr->assets = temp->assets;
			curr->equity = temp->equity;
			curr->liabilities = temp->liabilities;
			curr->left = deleteStd(curr->left, temp->id);
		}
	}
	return curr;
}




int main(){
//	createStd("mawdd", 10000, 9000);
	char id[100] = {};
	strcpy(id, generateId("mawdd"));
	root = insertStd(root, createStd("mawdd", id, 10000, 9000));
//	root = insertStd(root, createStd("dmwkd", "43234", 10000, 9000));
//	root = insertStd(root, createStd("efnjef", "1231", 10000, 9000));
//	root = insertStd(root, createStd("wadd", "123232", 10000, 9000));
//	root = insertStd(root, createStd("kmdkwdm", "3112", 10000, 9000));
//	root = deleteStd(root, "1231");
	view(root);
	return 0;
}
