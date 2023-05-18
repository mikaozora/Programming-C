#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Data{
	int value;
	int height;
	int total;
	char color[100];
	Data *left, *right;
}*root = NULL;

Data *createData(int value){
	Data *temp = (Data*)malloc(sizeof(Data));
	temp->value = value;
	temp->height = 1;
	temp->total = value;
	strcpy(temp->color, "white");
	temp->left = temp->right = NULL;
	return temp;
}

int max(int a, int b){
	return (a >= b ? a:b);
}

int getHeight(Data *curr){
	if(!curr){
		return 0;
	}
	return curr->height;
}

int getBf(Data *curr){
	if(!curr){
		return 0;
	}
	return getHeight(curr->left) - getHeight(curr->right);
}
int getTotal(Data *curr){
	if(!curr){
		return 0;
	}
	return curr->total;
}

Data *rightRotate(Data *t){
	Data *s = t->left;
	Data *b = s->right;
	t->left = b;
	s->right = t;
	
	t->height = 1 + max(getHeight(t->left), getHeight(t->right));
	s->height = 1 + max(getHeight(s->left), getHeight(s->right));
	
	t->total = t->value + getTotal(t->left) + getTotal(t->right);
	s->total = s->value + getTotal(s->left) + getTotal(s->right);
	
	if(getTotal(t->left) < getTotal(t->right)){
		strcpy(t->color, "pink");
	}else if(getTotal(t->left) > getTotal(t->right)){
		strcpy(t->color, "yellow");
	}else{
		strcpy(t->color, "white");
	}
	
	if(getTotal(s->left) < getTotal(s->right)){
		strcpy(s->color, "pink");
	}else if(getTotal(s->left) > getTotal(s->right)){
		strcpy(s->color, "yellow");
	}else{
		strcpy(s->color, "white");
	}
	return s;
}

Data *leftRotate(Data *t){
	Data *s = t->right;
	Data *b = s->left;
	t->right = b;
	s->left = t;
	
	t->height = 1 + max(getHeight(t->left), getHeight(t->right));
	s->height = 1 + max(getHeight(s->left), getHeight(s->right));
	
	t->total = t->value + getTotal(t->left) + getTotal(t->right);
	s->total = s->value + getTotal(s->left) + getTotal(s->right);
	
	if(getTotal(t->left) < getTotal(t->right)){
		strcpy(t->color, "pink");
	}else if(getTotal(t->left) > getTotal(t->right)){
		strcpy(t->color, "yellow");
	}else{
		strcpy(t->color, "white");
	}
	
	if(getTotal(s->left) < getTotal(s->right)){
		strcpy(s->color, "pink");
	}else if(getTotal(s->left) > getTotal(s->right)){
		strcpy(s->color, "yellow");
	}else{
		strcpy(s->color, "white");
	}
	
	return s;
}


Data *insertData(Data *curr, int value){
	if(!curr){
		return createData(value);
	}else if(value < curr->value){
		curr->left = insertData(curr->left, value);
	}else if(value > curr->value){
		curr->right = insertData(curr->right, value);
	}else{
		return curr;
	}
	curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
	curr->total = curr->value + getTotal(curr->left) + getTotal(curr->right);
	if(getTotal(curr->left) < getTotal(curr->right)){
		strcpy(curr->color, "pink");
	}else if(getTotal(curr->left) > getTotal(curr->right)){
		strcpy(curr->color, "yellow");
	}else{
		strcpy(curr->color, "white");
	}
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

Data *deleteData(Data *curr, int value){
	if(!curr){
		return curr;
	}else if(value < curr->value){
		curr->left = deleteData(curr->left, value);
	}else if(value > curr->value){
		curr->right = deleteData(curr->right, value);
	}else{
		if(!curr->left && !curr->right){
			free(curr);
			curr = NULL;
		}else if(!curr->right){
			Data *del = curr;
			curr = curr->left;
			free(del);
			del = NULL;
		}else if(!curr->left){
			Data *del = curr;
			curr = curr->right;
			free(del);
			del = NULL;
		}else{
			Data *temp = curr->left;
			while(temp->right){
				temp = temp->right;
			}
			curr->value = temp->value;
			curr->left = deleteData(curr->left, temp->value);
		}
		return curr;
	}
	curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
	curr->total = curr->value + getTotal(curr->left) + getTotal(curr->right);
	if(getTotal(curr->left) < getTotal(curr->right)){
		strcpy(curr->color, "pink");
	}else if(getTotal(curr->left) > getTotal(curr->right)){
		strcpy(curr->color, "yellow");
	}else{
		strcpy(curr->color, "white");
	}
	
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

void inDisplay(Data *curr){
	if(!curr){
		return;
	}
	inDisplay(curr->left);
	printf("%d %s\n", curr->value, curr->color);
	inDisplay(curr->right);
}

int pink, yellow, white;

void countColor(Data *curr, int value){
	if(!curr){
		return;
	}
	if(curr->value != value){
		if(strcmp(curr->color, "white") == 0){
			white++;
		}else if(strcmp(curr->color, "pink") == 0){
			pink++;
		}else if(strcmp(curr->color, "yellow") == 0){
			yellow++;
		}
	}
	countColor(curr->left, value);
	countColor(curr->right, value);
}

void describe(Data *curr, int value){
	if(!curr){
		return;
	}else if(value < curr->value){
		return describe(curr->left, value);
	}else if(value > curr->value){
		return describe(curr->right, value);
	}else{
		pink = 0;
		yellow = 0;
		white = 0;
		printf("value: %d\n", value);
		printf("keyword: %s\n", curr->color);
		countColor(curr, value);
		printf("number of pink children: %d\n", pink);
		printf("number of white children: %d\n", white);
		printf("number of yellow children: %d\n", yellow);
	}
}

int main(){
//	root = insertData(root, 10);
//	root = insertData(root, 11);
//	root = insertData(root, 12);
//	root = insertData(root, 13);
//	root = insertData(root, 14);
//	root = insertData(root, 15);
//	inDisplay(root);
//	describe(root, 11);

	int n, value;
	char input[100] = {};
	scanf("%d", &n); getchar();
	for(int i = 0; i < n; i++){
		scanf("%s", input); getchar();
		if(strcmp(input, "INSERT") == 0){
			scanf("%d", &value); getchar();
			root = insertData(root, value);
		}else if(strcmp(input, "DESCRIBE") == 0){
			scanf("%d", &value); getchar();
			describe(root, value);
		}else if(strcmp(input, "VIEW") == 0){
			inDisplay(root);
		}else if(strcmp(input, "DELETE") == 0){
			scanf("%d", &value); getchar();
			root = deleteData(root, value);
		}
	}
	
	return 0;
}
