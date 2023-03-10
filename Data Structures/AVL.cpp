#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct data
{
    int val;
    int height;

    struct data *left, *right;
} *root = NULL, *temp;

int max(int a, int b)
{
    return (a > b ? a : b);
}

int getHeight(struct data *curr)
{
    if (!curr)
    {
        return 0;
    }
    return curr->height;
}

int getBF(struct data *curr)
{
    if (!curr)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

struct data *rightRotation(struct data *t)
{
    struct data *s = t->left;
    struct data *b = s->right;
    t->left = b;
    s->right = t;

    // update height
    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));

    return s;
}

struct data *leftRotation(struct data *t)
{
    struct data *s = t->right;
    struct data *b = s->left;

    t->right = b;
    s->left = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));

    return s;
}

struct data *createData(int val)
{
    temp = (data *)malloc(sizeof(data));
    temp->val = val;
    temp->height = 1;
    temp->left = temp->right = NULL;
    return temp;
}

struct data *insertData(struct data *curr, int val)
{
    if (!curr)
    {
        return createData(val);
    }
    else if (val < curr->val)
    {
        curr->left = insertData(curr->left, val);
    }
    else if (val > curr->val)
    {
        curr->right = insertData(curr->right, val);
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
        return rightRotation(curr);
    }
    // RR
    if (bf < -1 && getBF(curr->right) <= 0)
    {
        return leftRotation(curr);
    }

    // LR
    if (bf > 1 && getBF(curr->left) < 0)
    {
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }

    // RL
    if (bf < -1 && getBF(curr->right) > 0)
    {
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }

    return curr;
}

void display(struct data *curr)
{
    if (!curr)
    {
        return;
    }
    printf("%d ", curr->val);
    display(curr->left);
    display(curr->right);
}

void peek()
{
    if (root)
    {
        printf("\nRoot: %d\n\n", root->val);
    }
}

struct data *deleteData(struct data *curr, int val)
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
            struct data *del = curr;
            curr = curr->left;
            free(del);
            del = NULL;
        }
        else if (!curr->left)
        {
            struct data *del = curr;
            curr = curr->right;
            free(del);
            del = NULL;
        }
        else
        {
            struct data *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            curr->val = temp->val;
            curr->left = deleteData(curr->left, temp->val);
        }
    }

    int bf = getBF(curr);

    // LL
    if (bf > 1 && getBF(curr->left) >= 0)
    {
        return rightRotation(curr);
    }
    // RR
    if (bf < -1 && getBF(curr->right) <= 0)
    {
        return leftRotation(curr);
    }

    // LR
    if (bf > 1 && getBF(curr->left) < 0)
    {
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }

    // RL
    if (bf < -1 && getBF(curr->right) > 0)
    {
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }

    return curr;
}

int main()
{
    root = insertData(root, 70);
    root = insertData(root, 80);
    root = insertData(root, 90);
    root = insertData(root, 100);
    root = insertData(root, 50);
    display(root);
    peek();
    printf("-----------\n");
    root = deleteData(root, 80);
    root = deleteData(root, 50);
    root = deleteData(root, 90);
    display(root);
    peek();
}