#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node{
    int age;
    Node *left, *right;
}*root = NULL;

Node *createNode(int age){
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->left = newNode->right = NULL;
    newNode->age = age;
    return newNode;
}

Node *insertNode(Node *curr, Node *newNode){
    if(!curr){
        return newNode;
    }else if(newNode->age < curr->age){
        curr->left = insertNode(curr->left, newNode);
    }else if(newNode->age > curr->age){
        curr->right = insertNode(curr->right, newNode);
    }
    return curr;
}

Node *deleteNode(Node *curr, int age){
    if(!curr){
        return curr;
    }else if(age < curr->age){
        curr->left = deleteNode(curr->left, age);
    }else if(age > curr->age){
        curr->right = deleteNode(curr->right, age);
    }else{
        if(!curr->left && !curr->right){
            free(curr);
            curr = NULL;
        }else if(!curr->left){
            Node *temp = curr;
            curr = curr->right;
            free(temp);
            temp = NULL;
        }else if(!curr->right){
            Node *temp = curr;
            curr = curr->left;
            free(temp);
            temp = NULL;
        }else{
            //predecessor
            Node *temp = curr->left;
            while(temp->right){
                temp = temp->right;
            }
            curr->age = temp->age;
            curr->left = deleteNode(curr->left, temp->age);

            //sucessor
            // Node *temp = curr->right;
            // while(temp->left){
            //     temp = temp->left;
            // }
            // curr->age = temp->age;
            // curr->right = deleteNode(curr->right, temp->age);
        }
    }
    return curr;
}

Node *deleteAll(Node *curr){
    while(curr){
        curr = deleteNode(curr, curr->age);
    }
    return curr;
}

void searchNode(Node *curr, int age){
    if(!curr){
        printf("data not found!\n");
    }else if(curr->age == age){
        printf("Data %d is found\n", age);
    }else if(curr->age > age){
        searchNode(curr->left, age);
    }else{
        searchNode(curr->right, age);
    }
    return;
}

void inTraversal(Node *curr){
    if(!curr){
        return;
    }
    inTraversal(curr->left);
    printf("%d\n", curr->age);
    inTraversal(curr->right);
}

void preTraversal(Node *curr){
    if(!curr){
        return;
    }
    printf("%d\n", curr->age);
    preTraversal(curr->left);
    preTraversal(curr->right);
}
void postTraversal(Node *curr){
    if(!curr){
        return;
    }
    postTraversal(curr->left);
    postTraversal(curr->right);
    printf("%d\n", curr->age);
}


int main(){
    root = insertNode(root, createNode(55));
    root = insertNode(root, createNode(23));
    root = insertNode(root, createNode(45));
    root = insertNode(root, createNode(80));
    root = insertNode(root, createNode(25));
    root = insertNode(root, createNode(21));
    root = insertNode(root, createNode(78));
    root = insertNode(root, createNode(56));

    preTraversal(root);
    // preTraversal(root);
    // postTraversal(root);
    searchNode(root, 70);

    deleteNode(root, 55);
    printf("\n");
    preTraversal(root);

    root = deleteAll(root);
    preTraversal(root);
} 