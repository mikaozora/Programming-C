#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    int value;

    struct data *left;
    struct data *right;

} *root = NULL;

struct data *createData(int value)
{
    struct data *temp = (struct data *)malloc(sizeof(struct data));
    temp->value = value;
    temp->right = temp->left = NULL;
    return temp;
}

void insert(struct data *curr, int newValue)
{
    if (!curr)
    {
        root = createData(newValue);
    }
    else if (newValue < curr->value && curr->left == NULL)
    {
        curr->left = createData(newValue);
    }
    else if (newValue > curr->value && curr->right == NULL)
    {
        curr->right = createData(newValue);
    }
    else if (newValue > curr->value)
    {
        insert(curr->right, newValue);
    }
    else if (newValue < curr->value)
    {
        insert(curr->left, newValue);
    }
    else
    {
        return;
    }
}

void displayInfix(struct data *curr)
{
    if (curr->left)
    {
        displayInfix(curr->left);
    }
    printf("%d ", curr->value);
    if (curr->right)
    {
        displayInfix(curr->right);
    }
}

void search(struct data *curr, int value)
{
    if (curr == NULL)
    {
        printf("\n%d is not found in BST\n", value);
        return;
    }
    if (curr->value == value)
    {
        printf("\n%d is found in BST\n", value);
        return;
    }

    if (value < curr->value)
    {
        search(curr->left, value);
    }
    if (value > curr->value)
    {
        search(curr->right, value);
    }
}

struct data *delRec(struct data *parent, struct data *curr){
    if(curr->left == NULL && curr->right == NULL){
        free(curr);
        return NULL;
    }else if(curr->left != NULL && curr->right == NULL){
        // parent->left = curr->left;
        // free(curr);
        return curr->left;

    }else if(curr->left == NULL && curr->right != NULL){
        // parent->right = curr->right;
        // free(curr);
        return curr->right;
    }
}
struct data *parent = NULL;
void deleteNode(int value, struct data *curr){
    if(curr == NULL){
        printf("%d is not available to delete\n", value);
        return;
    }

    if(curr->value == value){
        
        curr = delRec(parent, curr);
        if(value > parent->value){
            parent->right = curr;
        }else{
            parent->left = curr;
        }
        return;
    }
    if(value < curr->value){
        parent = curr;
        deleteNode(value, curr->left);
    }else if(value > curr->value){
        parent = curr;
        deleteNode(value, curr->right);
    }
}



int main()
{
    insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 50);
    displayInfix(root);
    search(root, 5);
    deleteNode(30, root);
    displayInfix(root);
}