#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Game
{
    char title[100];
    char genre[100];
    int stock;
    int height;
    Game *left, *right;
} *root = NULL;

Game *createGame(const char *title, const char *genre, int stock)
{
    Game *temp = (Game *)malloc(sizeof(Game));
    strcpy(temp->title, title);
    strcpy(temp->genre, genre);
    temp->stock = stock;
    temp->height = 1;
    temp->left = temp->right = NULL;
    return temp;
}

int max(int a, int b)
{
    return (a > b ? a : b);
}

int getHeight(Game *curr)
{
    if (!curr)
    {
        return 0;
    }
    return curr->height;
}

int getBf(Game *curr)
{
    if (!curr)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

Game *rightRotate(Game *t)
{
    Game *s = t->left;
    Game *b = s->right;
    t->left = b;
    s->right = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));
    return s;
}

Game *leftRotate(Game *t)
{
    Game *s = t->right;
    Game *b = s->left;
    t->right = b;
    s->left = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));
    return s;
}

Game *insertGame(Game *curr, Game *newGame)
{
    if (!curr)
    {
        return newGame;
    }
    else if (strcmp(newGame->title, curr->title) < 0)
    {
        curr->left = insertGame(curr->left, newGame);
    }
    else if (strcmp(newGame->title, curr->title) > 0)
    {
        curr->right = insertGame(curr->right, newGame);
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

Game *deleteGame(Game *curr, const char *title)
{
    if (!curr)
    {
        return curr;
    }
    else if (strcmp(title, curr->title) < 0)
    {
        curr->left = deleteGame(curr->left, title);
    }
    else if (strcmp(title, curr->title) > 0)
    {
        curr->right = deleteGame(curr->right, title);
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
            Game *del = curr;
            curr = curr->left;
            free(del);
            del = NULL;
        }
        else if (!curr->left)
        {
            Game *del = curr;
            curr = curr->right;
            free(del);
            del = NULL;
        }
        else
        {
            Game *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            strcpy(curr->title, temp->title);
            strcpy(curr->genre, temp->genre);
            curr->stock = temp->stock;
            curr->left = deleteGame(curr->left, temp->title);
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

void inDisplay(Game *curr)
{
    if (!curr)
    {
        return;
    }
    inDisplay(curr->left);
    printf("| %-30s| %-15s| %-15d|\n", curr->title, curr->genre, curr->stock);
    printf("-------------------------------------------------------------------\n");
    inDisplay(curr->right);
}

int validateGenre(const char *genre)
{
    if (strcmp(genre, "Action") == 0)
    {
        return 1;
    }
    else if (strcmp(genre, "RPG") == 0)
    {
        return 1;
    }
    else if (strcmp(genre, "Adventure") == 0)
    {
        return 1;
    }
    else if (strcmp(genre, "Card Game") == 0)
    {
        return 1;
    }
    return 0;
}

int validateTitle(Game *curr, const char *title)
{
    if (!curr)
    {
        return 0;
    }
    else if (strcmp(title, curr->title) < 0)
    {
        return validateTitle(curr->left, title);
    }
    else if (strcmp(title, curr->title) > 0)
    {
        return validateTitle(curr->right, title);
    }
    else
    {
        return 1;
    }
}

void insertProc()
{
    char title[100] = {};
    char genre[100] = {};
    int stock;
    int valGenre = 0;
    int valTitle = 0;
    do
    {
        valTitle = 0;
        printf("Input game title[5-25][unique]: ");
        scanf("%[^\n]", title);
        valTitle = validateTitle(root, title);
        if (valTitle == 1)
        {
            printf("Please input unique title\n");
        }
        getchar();
    } while (strlen(title) < 5 || strlen(title) > 25 || valTitle == 1);
    do
    {
        printf("Input Game Type[Action][RPG][Adventure][Card Game]: ");
        scanf("%[^\n]", genre);
        getchar();
        valGenre = validateGenre(genre);
    } while (valGenre != 1);
    valGenre = 0;
    do
    {
        printf("Input game stock[>= 1]: ");
        scanf("%d", &stock);
        getchar();
    } while (stock < 1);
    root = insertGame(root, createGame(title, genre, stock));
    printf("Insert success !\n");
}

Game *findGameData(Game *curr, const char *title)
{
    if (!curr)
    {
        printf("Data not found !\n\n");
        printf("Press Enter to Continue...");
        getchar();
        return NULL;
    }
    else if (strcmp(title, curr->title) < 0)
    {
        return findGameData(curr->left, title);
    }
    else if (strcmp(title, curr->title) > 0)
    {
        return findGameData(curr->right, title);
    }
    else
    {
        printf("Current stock: %d\n\n", curr->stock);
        return curr;
    }
}

int validateUpdateType(const char *input)
{
    if (strcmpi(input, "add") == 0)
    {
        return 1;
    }
    else if (strcmpi(input, "remove") == 0)
    {
        return 2;
    }
    return 0;
}

void updateProc()
{
    char title[100] = {};
    char input[100] = {};
    int valInput = 0;
    int stock;
    Game *temp;
    printf("Input game title: ");
    scanf("%[^\n]", title);
    getchar();
    temp = findGameData(root, title);
    do
    {
        valInput = 0;
        printf("Input update type[add|remove][case insensitive]: ");
        scanf("%[^\n]", input);
        valInput = validateUpdateType(input);
        getchar();
    } while (valInput == 0);

    if (valInput == 1)
    {
        do
        {
            printf("Input stock to add: ");
            scanf("%d", &stock);
            getchar();
        } while (stock < 1);
        temp->stock += stock;
    }
    else if (valInput == 2)
    {
        do
        {
            printf("Input stock to remove[1-%d]: ", temp->stock);
            scanf("%d", &stock);
            getchar();
        } while (stock < 1 || stock > temp->stock);
        temp->stock -= stock;
    }
    printf("Data updated Succesfully!\n");
    if (temp->stock == 0)
    {
        printf("%s is removed from the warehouse !\n\n", temp->title);
        root = deleteGame(root, title);
    }
    printf("Press enter to continue...");
    getchar();
}

int main()
{
    // root = insertGame(root, createGame("dota 4", "Action", 50));
    // root = insertGame(root, createGame("pes", "RPG", 50));
    // root = insertGame(root, createGame("Mortal combat", "Adventure", 50));

    // inDisplay(root);

    // printf("\n");
    // root = deleteGame(root, "dota 5");
    // inDisplay(root);

    int choose;
    do
    {
        printf("Blujack GShop\n");
        printf("==================\n");
        printf("1. Insert Game\n2. View Game\n3. Update Stock\n4. Exit\n>> ");
        scanf("%d", &choose);
        getchar();
        switch (choose)
        {
        case 1:
            insertProc();
            break;
        case 2:
            if (!root)
            {
                printf("Warehouse is empty!\n\n");
                printf("Press enter to continue...");
                getchar();
            }
            else
            {
                printf("-------------------------------------------------------------------\n");
                printf("| %-30s| %-15s| %-15s|\n", "Game Title", "Game Genre", "Game Stock");
                printf("-------------------------------------------------------------------\n");
                inDisplay(root);
            }

            break;
        case 3:
            updateProc();
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (choose != 4);
}