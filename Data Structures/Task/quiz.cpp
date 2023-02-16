#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    char name[100];
    char NIM[100];
    Node *left, *right;
} *root = NULL;

int i = 1;

Node *createNode(const char *name, const char *NIM)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name);
    strcpy(temp->NIM, NIM);
    temp->left = temp->right = NULL;
    return temp;
}

void view(Node *curr)
{
    if (!root)
    {
        printf("Please insert data!\n");
        return;
    }
    if (!curr)
    {
        return;
    }
    view(curr->left);
    printf("| %4d | %-15s | %-15s |\n", i, curr->name, curr->NIM);
    i++;
    view(curr->right);
}

Node *insertNode(Node *curr, Node *newNode)
{
    if (!curr)
    {
        return newNode;
    }
    else if (strcmpi(newNode->name, curr->name) < 0)
    {
        curr->left = insertNode(curr->left, newNode);
    }
    else if (strcmpi(newNode->name, curr->name) > 0)
    {
        curr->right = insertNode(curr->right, newNode);
    }
}

Node *deleteNode(Node *curr, const char *name)
{
    if (!curr)
    {
        printf("Cannot delete because student name does not exist.\n");
        return curr;
    }
    else if (strcmpi(name, curr->name) < 0)
    {
        curr->left = deleteNode(curr->left, name);
    }
    else if (strcmpi(name, curr->name) > 0)
    {
        curr->right = deleteNode(curr->right, name);
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
            Node *del = curr;
            curr = curr->right;
            free(del);
            del = NULL;
        }
        else if (!curr->right)
        {
            Node *del = curr;
            curr = curr->left;
            free(del);
            del = NULL;
        }
        else
        {
            Node *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            strcpy(curr->name, temp->name);
            strcpy(curr->NIM, temp->NIM);
            curr->left = deleteNode(curr->left, temp->name);
        }
    }
    return curr;
}

int searchNode(Node *curr, Node *newNode)
{
    if (!curr)
    {
        return 0;
    }
    else if (strcmpi(newNode->name, curr->name) == 0)
    {
        strcpy(curr->NIM, newNode->NIM);
        return 1;
    }
    else if (strcmpi(newNode->name, curr->name) < 0)
    {
        searchNode(curr->left, newNode);
    }
    else if (strcmpi(newNode->name, curr->name) > 0)
    {
        searchNode(curr->right, newNode);
    }
    // return;
}

int checkNIM(const char *NIM)
{
    int res = 1;
    if (strlen(NIM) == 8)
    {
        for (int i = 0; i < 8; i++)
        {
            // printf("%c %d\n", NIM[i], isdigit(NIM[i]));
            if (isdigit(NIM[i]) == 0)
            {
                return 0;
            }
        }
    }
    else
    {
        return 0;
    }
    return res;
}

int main()
{
    // dummy
    // root = insertNode(root, createNode("mika", "12345"));
    // root = insertNode(root, createNode("abdi", "12345"));
    // root = insertNode(root, createNode("gladis", "12345"));
    // root = insertNode(root, createNode("goran", "12345"));
    // root = insertNode(root, createNode("apeng", "12345"));
    // root = insertNode(root, createNode("stefi", "12345"));

    int choose;
    char name[100] = {};
    char NIM[100] = {};
    do
    {
        printf("===== Menu ======\n");
        printf("1. View Student\n");
        printf("2. Add Student\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choose);
        getchar();
        switch (choose)
        {
        case 1:
            i = 1;
            printf("======================================================\n");
            printf("| %4s | %-15s | %-15s |\n", "No", "Name", "NIM");
            view(root);
            printf("======================================================\n");
            break;
        case 2:
            do
            {
                printf("Name: ");
                scanf("%[^\n]", name);
                getchar();
            } while (strlen(name) < 3 || strlen(name) > 50);
            do
            {
                printf("NIM: ");
                scanf("%[^\n]", NIM);
                getchar();
            } while (checkNIM(NIM) != 1);
            if (searchNode(root, createNode(name, NIM)) == 1)
            {
                searchNode(root, createNode(name, NIM));
                printf("Student name already exists! updated NIM instead.\n");
            }
            else
            {
                root = insertNode(root, createNode(name, NIM));
            }
            break;
        case 3:
            i = 1;
            printf("======================================================\n");
            printf("| %4s | %-15s | %-15s |\n", "No", "Name", "NIM");
            view(root);
            printf("======================================================\n");
            do
            {
                printf("Insert name want to delete: ");
                scanf("%[^\n]", name);
                getchar();
            } while (strlen(name) < 3 || strlen(name) > 50);
            root = deleteNode(root, name);
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (choose != 4);

    return 0;
}