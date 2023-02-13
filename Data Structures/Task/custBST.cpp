#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Member
{
    char name[100];
    Member *left, *right;
} *rootMember = NULL;

struct Node
{
    char name[100];
    Member membership;
    Node *left, *right;
} *root = NULL;

Node *createNode(char const *name, char const *membership)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    strcpy(temp->name, name);
    strcpy(temp->membership.name, membership);
    temp->right = temp->left = NULL;
    return temp;
}

int searchMember(Member *curr, char const member[100])
{
    if (!curr)
    {
        return 0;
    }
    else if (strcmp(member, curr->name) == 0)
    {
        return 1;
    }
    else if (strcmp(member, curr->name) < 0)
    {
        searchMember(curr->left, member);
    }
    else if (strcmp(member, curr->name) > 0)
    {
        searchMember(curr->right, member);
    }
}

void searchCust(Node *curr, char const name[100], char const member[100])
{
    if (!curr)
    {
        printf("ga ketemu\n");
        return;
    }
    else if (strcmp(name, curr->name) == 0)
    {
        printf("ketemu\n");
        strcpy(curr->membership.name, member);
        return;
    }
    else if (strcmp(name, curr->name) < 0)
    {
        searchCust(curr->left, name, member);
        return;
    }
    else if (strcmp(name, curr->name) > 0)
    {
        searchCust(curr->right, name, member);
        return;
    }
}

Node *insertNode(Node *curr, Node *newNode)
{
    int res = searchMember(rootMember, newNode->membership.name);
    if (res == 1)
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
        // strcpy(curr->membership.name, newNode->membership.name);
        return curr;
    }
    else
    {
        return NULL;
    }
}

Node *deleteNode(Node *curr, char const name[100])
{
    if (!curr)
    {
        printf("Data not found\n");
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
        if (!curr->right && !curr->left)
        {
            printf("deleted\n");
            free(curr);
            curr = NULL;
        }
        else if (!curr->left)
        {
            printf("deleted heres\n");
            Node *temp = curr;
            curr = curr->right;
            free(temp);
            temp = NULL;
        }
        else if (!curr->right)
        {
            printf("deleted here\n");
            Node *temp = curr;
            curr = curr->left;
            free(temp);
            temp = NULL;
        }
        else
        {
            Node *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            strcpy(curr->name, temp->name);
            strcpy(curr->membership.name, temp->membership.name);
            curr->left = deleteNode(curr->left, temp->name);
        }
    }
    return curr;
}

Member *createNodeMember(char const name[100])
{
    Member *temp = (Member *)malloc(sizeof(Member));
    strcpy(temp->name, name);
    temp->right = temp->left = NULL;
}

Member *insertMember(Member *curr, Member *newNode)
{
    if (!curr)
    {
        return newNode;
    }
    else if (strcmp(newNode->name, curr->name) < 0)
    {
        curr->left = insertMember(curr->left, newNode);
    }
    else if (strcmp(newNode->name, curr->name) > 0)
    {
        curr->right = insertMember(curr->right, newNode);
    }
    return curr;
}

void inTraversalMember(Member *curr)
{
    if (!curr)
    {
        return;
    }
    inTraversalMember(curr->left);
    printf("%s\n", curr->name);
    inTraversalMember(curr->right);
}

void inTraversalNode(Node *curr)
{
    if (!curr)
    {
        return;
    }
    inTraversalNode(curr->left);
    printf("%s - %s\n", curr->name, curr->membership.name);
    inTraversalNode(curr->right);
}

void addCustomer()
{
    char name[100] = {};
    char membership[100] = {};
    Node *temp, *resCust;
    do
    {
        printf("Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);
    do
    {
        printf("Membership: ");
        scanf("%[^\n]", membership);
        getchar();
        // if (!resCust)
        // {
        //     printf("ini lo ga ketemu\n");
        //     temp = insertNode(root, createNode(name, membership));
        // }else{
        //     printf("ketemuu bro %s\n", resCust->name);
        //     temp = insertNode(root, createNode(resCust->name, membership));
        // }
        temp = insertNode(root, createNode(name, membership));
    } while (!temp);
    searchCust(root, name, membership);
    root = temp;
}

void deleteCustomer()
{
    char name[100] = {};
    do
    {
        printf("Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while (strlen(name) < 3 || strlen(name) > 50);
    root = deleteNode(root, name);
    printf("Successfully delete\n");
}

int main()
{
    rootMember = insertMember(rootMember, createNodeMember("Non-Member"));
    rootMember = insertMember(rootMember, createNodeMember("Bronze"));
    rootMember = insertMember(rootMember, createNodeMember("Silver"));
    rootMember = insertMember(rootMember, createNodeMember("Gold"));
    rootMember = insertMember(rootMember, createNodeMember("Platinum"));
    root = insertNode(root, createNode("mika", "Platinum"));
    root = insertNode(root, createNode("abdi", "Gold"));
    root = insertNode(root, createNode("hero", "Bronze"));

    int choose = 0;
    do
    {
        printf("Welcome to Hovs Fresh Concoction\n");
        printf("1. Add customer\n");
        printf("2. View Customer\n");
        printf("3. Remove Customer\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &choose);
        getchar();
        switch (choose)
        {
        case 1:
            addCustomer();
            break;
        case 2:
            inTraversalNode(root);
            break;
        case 3:
            deleteCustomer();
            break;
        }
    } while (choose != 4);
}