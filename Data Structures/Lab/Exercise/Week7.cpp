#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Food{
    char name[100];
    int price;
    int height;
    Food *left, *right;
};

Food *createFood(const char *name, int price){
    Food *temp = (Food *) malloc(sizeof(Food));
    strcpy(temp->name, name);
    temp->price = price;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int max(int a, int b){
    return (a >= b ? a : b);
}

// int calcHeight(Food *curr){
//     if(!curr){
//         return 0;
//     }
//     int leftHeight = calcHeight(curr->left);
//     int rightHeight = calcHeight(curr->right);

//     return 1 + max(leftHeight, rightHeight);
// }

int calcHeight(Food *curr){
    return (!curr) ? 0 : 1 + max(calcHeight(curr->left), calcHeight(curr->right));
}

int getBalance(Food *root){
    return (!root) ? 0 : calcHeight(root->left) - calcHeight(root->right);
}

Food *rightRotate(Food *root){
    Food *newParent = root->left;
    root->left = newParent->right;
    newParent->right = root;

    root->height = calcHeight(root);
    newParent->height = calcHeight(newParent);

    return newParent;
}

Food *leftRotate(Food *root){
    Food *newParent = root->right;
    root->right = newParent->left;
    newParent->left = root;

    root->height = calcHeight(root);
    newParent->height = calcHeight(newParent);

    return newParent;
}

Food *insertFood(Food *root, const char *name, int price){
    if(!root){
        return createFood(name, price);
    }else if(price < root->price){
        root->left = insertFood(root->left, name, price);
    }else if(price > root->price){
        root->right = insertFood(root->right, name, price);
    }
    root->height = calcHeight(root);
    int balance = getBalance(root);

    if(balance > 1){
        if(price > root->price){
            root->left = leftRotate(root->left);
        }
        return rightRotate(root);
    }else if(balance < -1){
        if(price < root->price){
            root->right = rightRotate(root->right);
        }
        return leftRotate(root);
    }

    return root;
}

Food *updateFood(Food *root, int price, const char* name){
    if(!root){
        printf("Data not found\n");
        return root;
    }else if(price < root->price){
        root->left = updateFood(root->left, price, name);
    }else if(price > root->price){
        root->right = updateFood(root->right, price, name);
    }else{
        strcpy(root->name, name);
        printf("Successfully updated\n");
    }
    return root;
}

Food *deleteFood(Food* root, int price){
    if(!root){
        return root;
    }else if(price < root->price){
        root->left = deleteFood(root->left, price);
    }else if(price > root->price){
        root->right = deleteFood(root->right, price);
    }else{
        if(!root->left && !root->right){
            free(root);
            root = NULL;
        }else if(!root->left){
            Food *del = root;
            root = del->right;
            free(del);
            del = NULL;
        }else if(!root->right){
            Food *del = root;
            root = del->left;
            free(del);
            del = NULL;
        }else{
            Food *temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            strcpy(root->name, temp->name);
            root->price = temp->price;  
            root->left = deleteFood(root->left, temp->price);
        }
    }

    int balance = getBalance(root);

    if(balance > 1){
        if(price > root->left->price){
            root->left = leftRotate(root->left);
        }
        return rightRotate(root);
    }else if(balance < -1){
        if(price < root->right->price){
            root->right = rightRotate(root->right);
        }
        return leftRotate(root);
    }

    return root;
}

void display(Food *curr){
    if(!curr){
        return;
    }
    display(curr->left);
    printf("%s - %d - %d - (%d)\n", curr->name, curr->price, curr->height, getBalance(curr));
    display(curr->right);
}



int main(){
    Food *root = insertFood(NULL, "seblak", 10000);
    root = insertFood(root, "naspad", 200000);
    root = insertFood(root, "sate ular", 15000);
    root = insertFood(root, "Sate hamster", 500000);
    root = insertFood(root, "Sate badak", 100);
    root = insertFood(root, "Mie ayam", 5000);
    root = insertFood(root, "Soto malaysia", 9000);
    root = insertFood(root, "Soto Ketan", 800000);
    root = insertFood(root, "Aqua", 1234);
    display(root);
    printf("================\n");
    root = updateFood(root, 10000, "Pecel lele");
    display(root);
    root = deleteFood(root, 1);
    printf("=================\n");
    display(root);

    return 0;
}