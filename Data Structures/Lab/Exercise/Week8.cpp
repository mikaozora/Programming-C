#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Property
{
    char id[6];
    int N;
    int length;
    char type[20];
    int height;
    Property *left, *right;
} *root = NULL;

Property *createProeprty(const char *id, int N, int length, const char *type)
{
    Property *temp = (Property *)malloc(sizeof(Property));
    strcpy(temp->id, id);
    strcpy(temp->type, type);
    temp->N = N;
    temp->length = length;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

int max(int a, int b)
{
    return (a >= b ? a : b);
}

int getHeight(Property *curr)
{
    if (!curr)
    {
        return 0;
    }
    return curr->height;
}

int getBf(Property *curr)
{
    if (!curr)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

Property *rightRotate(Property *t)
{
    Property *s = t->left;
    Property *b = s->right;
    t->left = b;
    s->right = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));
    return s;
}

Property *leftRotate(Property *t)
{
    Property *s = t->right;
    Property *b = s->left;
    t->right = b;
    s->left = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));
    return s;
}

Property *insertProperty(Property *curr, Property *newProperty)
{
    if (!curr)
    {
        return newProperty;
    }
    else if (strcmp(newProperty->id, curr->id) < 0)
    {
        curr->left = insertProperty(curr->left, newProperty);
    }
    else if (strcmp(newProperty->id, curr->id) > 0)
    {
        curr->right = insertProperty(curr->right, newProperty);
    }
    else
    {
        return curr;
    }

    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    int bf = getBf(curr);
    if (bf > 1 && getBf(curr->left) >= 0)
    {
        return rightRotate(curr);
    }
    if (bf < -1 && getBf(curr->right) <= 0)
    {
        return leftRotate(curr);
    }
    if (bf > 1 && getBf(curr->left) < 0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    if (bf < -1 && getBf(curr->right) > 0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

Property *deleteProperty(Property *curr, const char *id)
{
    if (!curr)
    {
        return curr;
    }
    else if (strcmp(id, curr->id) < 0)
    {
        curr->left = deleteProperty(curr->left, id);
    }
    else if (strcmp(id, curr->id) > 0)
    {
        curr->right = deleteProperty(curr->right, id);
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
            Property *del = curr;
            curr = curr->left;
            free(del);
            del = NULL;
        }
        else if (!curr->left)
        {
            Property *del = curr;
            curr = curr->right;
            free(del);
            del = NULL;
        }
        else
        {
            Property *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            strcpy(curr->id, temp->id);
            strcpy(curr->type, temp->type);
            curr->N = temp->N;
            curr->length = temp->length;
            curr->left = deleteProperty(curr->left, temp->id);
        }
        return curr;
    }
    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    int bf = getBf(curr);
    if (bf > 1 && getBf(curr->left) >= 0)
    {
        return rightRotate(curr);
    }
    if (bf < -1 && getBf(curr->right) <= 0)
    {
        return leftRotate(curr);
    }
    if (bf > 1 && getBf(curr->left) < 0)
    {
        curr->left = leftRotate(curr->left);
        return rightRotate(curr);
    }
    if (bf < -1 && getBf(curr->right) > 0)
    {
        curr->right = rightRotate(curr->right);
        return leftRotate(curr);
    }
    return curr;
}

long long int generatePrice(const char *type, int N, int length)
{
    long long int landPrice = 0;
    double area = 0;
    long long int price = 0;
    if (strcmp(type, "rural") == 0)
    {
        landPrice = 2000;
    }
    else if (strcmp(type, "metro") == 0)
    {
        landPrice = 5500;
    }
    else if (strcmp(type, "capital") == 0)
    {
        landPrice = 10000;
    }

    if (N == 4)
    {
        area = length * length;
    }
    else
    {
        area = (N * pow(length, 2)) / (4 * tan(3.14 / N));
    }
    price = area * landPrice;
    printf("%lld * %lld = %lld\n", area, landPrice, price);
    return price;
}

void preDisplay(Property *curr)
{
    if (!curr)
    {
        return;
    }
    // print
    printf("| %5s, | %-2d | %-4d | %-20s | %ld |\n", curr->id, curr->N, curr->length, curr->type, 0);
    preDisplay(curr->left);
    preDisplay(curr->right);
}

void inDisplay(Property *curr)
{
    if (!curr)
    {
        return;
    }
    inDisplay(curr->left);
    // print
    long long int price = generatePrice(curr->type, curr->N, curr->length);
    printf("| %5s, | %-2d | %-4d | %-20s | %lld |\n", curr->id, curr->N, curr->length, curr->type, price);
    inDisplay(curr->right);
}

Property *searchProperty(Property *curr, const char *id)
{
    if (!curr)
    {
        return NULL;
    }
    else if (strcmp(id, curr->id) < 0)
    {
        return searchProperty(curr->left, id);
    }
    else if (strcmp(id, curr->id) > 0)
    {
        return searchProperty(curr->right, id);
    }
    else
    {
        return curr;
    }
}

Property *deleteAll(Property *curr)
{
    while (curr)
    {
        deleteProperty(curr, curr->id);
    }
    return curr;
}

int main()
{
    root = insertProperty(root, createProeprty("TX000", 5, 1, "rural"));
    root = insertProperty(root, createProeprty("TX004", 4, 5, "capital"));
    // root = insertProperty(root, createProeprty("TX001", 4, 50, "rural"));
    // root = insertProperty(root, createProeprty("TX002", 7, 15, "rural"));
    root = insertProperty(root, createProeprty("TX005", 6, 10, "metro"));
    root = insertProperty(root, createProeprty("TX003", 10, 1000, "capital"));
    inDisplay(root);

    // printf("\n");
    // root = deleteProperty(root, "TX001");
    // inDisplay(root);
}