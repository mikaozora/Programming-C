#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int value;
    Node *left, *right;
} *root = NULL;

Node *createNode(int value)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *insertNode(Node *curr, Node *node)
{
    if (!curr)
    {
        return node;
    }
    else if (node->value < curr->value)
    {
        curr->left = insertNode(curr->left, node);
    }
    else if (node->value > curr->value)
    {
        curr->right = insertNode(curr->right, node);
    }
    return curr;
}

void inOrder(Node *curr)
{
    if (!curr)
    {
        return;
    }
    inOrder(curr->left);
    printf("%d\n", curr->value);
    inOrder(curr->right);
}
void preOrder(Node *curr)
{
    if (!curr)
    {
        return;
    }
    printf("%d\n", curr->value);
    preOrder(curr->left);
    preOrder(curr->right);
}

void postOrder(Node *curr)
{
    if (!curr)
    {
        return;
    }

    postOrder(curr->left);
    postOrder(curr->right);
    printf("%d\n", curr->value);
}

Node *deleteNode(Node *curr, int value)
{
    if (!curr)
    {
        return curr;
    }
    else if (value < curr->value)
    {
        curr->left = deleteNode(curr->left, value);
    }
    else if (value > curr->value)
    {
        curr->right = deleteNode(curr->right, value);
    }
    else
    {
        if (!curr->left && !curr->right)
        {
            free(curr);
            curr = NULL;
        }
        else if (!curr->left)
        {
            Node *temp = curr;
            curr = curr->right;
            free(temp);
            temp = NULL;
        }
        else if (!curr->right)
        {
            Node *temp = curr;
            curr = curr->left;
            free(temp);
            temp = NULL;
        }
        else
        {
            // predecessor
            // Node *temp = curr->left;
            // while(temp->right){
            //     temp = temp->right;
            // }
            // curr->value = temp->value;
            // curr->left = deleteNode(curr->left, temp->value);

            // successor
            Node *temp = curr->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            curr->value = temp->value;
            curr->right = deleteNode(curr->right, temp->value);
        }
    }
    return curr;
}

Node *deleteAll(Node *curr)
{

    while (curr)
    {
        curr = deleteNode(curr, curr->value);
    }
    return curr;
}

Node *searchNode(Node *curr, int value)
{
    if (!curr)
    {
        return curr;
    }
    else if (curr->value == value)
    {
        return curr;
    }
    else if (value < curr->value)
    {
        return searchNode(curr->left, value);
    }
    else
    {
        return searchNode(curr->right, value);
    }
}

int main()
{

    root = insertNode(root, createNode(10));
    root = insertNode(root, createNode(50));
    root = insertNode(root, createNode(100));
    root = insertNode(root, createNode(5));
    root = insertNode(root, createNode(20));
    root = insertNode(root, createNode(15));
    // inOrder(root);
    preOrder(root);
    // postOrder(root);
    deleteNode(root, 20);
    printf("\n\n");
    root = insertNode(root, createNode(35));
    root = insertNode(root, createNode(55));
    root = insertNode(root, createNode(43));
    preOrder(root);

    root = deleteAll(root);
    printf("\n");
    preOrder(root);
}