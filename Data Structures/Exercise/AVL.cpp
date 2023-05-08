#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct data
{
    int val;
    int height;

    struct data *left, *right;
} *root = NULL, *temp;

data *createData(int val)
{
    temp = (data *)malloc(sizeof(data));
    temp->val = val;
    temp->height = 1;
    temp->left = temp->right = NULL;
    return temp;
}

int max(int a, int b)
{
    return (a >= b ? a : b);
}

int getHeight(data *curr)
{
    if (!curr)
    {
        return 0;
    }
    return curr->height;
}

int getBF(data *curr)
{
    if (!curr)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

data *rightRotate(data *t)
{
    data *s = t->left;
    data *b = s->right;
    t->left = b;
    s->right = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));
    return s;
}
data *leftRotate(data *t)
{
    data *s = t->right;
    data *b = s->left;
    t->right = b;
    s->left = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));
    return s;
}

data *insertData(data *curr, data *newData)
{
    if (!curr)
    {
        return newData;
    }
    else if (newData->val < curr->val)
    {
        curr->left = insertData(curr->left, newData);
    }
    else if (newData->val > curr->val)
    {
        curr->right = insertData(curr->right, newData);
    }
    else
    {
        return curr;
    }
    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    int bf = getBF(curr);

    // LL
    if (bf > 1 && getBF(curr->left) >= 0)
    {
        return rightRotate(curr);
    }
    if (bf < -1 && getBF(curr->right) <= 0)
    {
        return leftRotate(curr);
    }
    if (bf > 1 && getBF(curr->left) < 0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    if (bf < -1 && getBF(curr->right) > 0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

data *deleteData(data *curr, int val)
{
    if (!curr)
    {
        return NULL;
    }
    else if (val < curr->val)
    {
        curr->left = deleteData(curr->left, val);
    }
    else if (val > curr->val)
    {
        curr->right = deleteData(curr->right, val);
    }
    else
    {
        if (!curr->right && !curr->left)
        {
            free(curr);
            curr = NULL;
        }
        else if (!curr->right)
        {
            data *del = curr;
            curr = curr->left;
            free(del);
            del = NULL;
        }
        else if (!curr->left)
        {
            data *del = curr;
            curr = curr->right;
            free(del);
            del = NULL;
        }
        else
        {
            data *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            curr->val = temp->val;
            curr->left = deleteData(curr->left, temp->val);
        }
        return curr;
    }
    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    int bf = getBF(curr);

    // LL
    if (bf > 1 && getBF(curr->left) >= 0)
    {
        return rightRotate(curr);
    }
    if (bf < -1 && getBF(curr->right) <= 0)
    {
        return leftRotate(curr);
    }
    if (bf > 1 && getBF(curr->left) < 0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    if (bf < -1 && getBF(curr->right) > 0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

void display(data *curr)
{
    if (!curr)
    {
        return;
    }
    display(curr->left);
    printf("%d (%d - (%d))\n", curr->val, curr->height, getBF(curr));
    display(curr->right);
}

int findValue(data *curr, int val)
{
    if (!curr)
    {
        return 0;
    }
    if (val == curr->val)
    {
        printf("%d %d\n", curr->val, val);
        return 1;
    }
    findValue(curr->left, val);
    findValue(curr->right, val);
}

void displayRoot()
{
    if (root)
    {
        printf("Root = %d\n", root->val);
    }
}

int main()
{
    root = insertData(root, createData(50));
    root = insertData(root, createData(30));
    root = insertData(root, createData(20));
    root = insertData(root, createData(90));
    root = insertData(root, createData(35));
    root = insertData(root, createData(70));
    root = insertData(root, createData(99));
    root = insertData(root, createData(31));
    display(root);
    displayRoot();

    int res = findValue(root, 500);
    printf("val = %d\n", res);
    printf("\n");

    root = deleteData(root, 30);
    root = deleteData(root, 90);
    root = deleteData(root, 31);
    root = deleteData(root, 35);
    root = deleteData(root, 20);
    display(root);
    displayRoot();
    printf("\n");
}