#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

int i = 0;

struct Game
{
    char name[200];
    int rate, hours;
    Game *left, *right, *next;
} *root = NULL, *head = NULL, *tail = NULL;

Game *createStd(const char *name, int rate, int hours)
{
    Game *temp = (Game *)malloc(sizeof(Game));
    strcpy(temp->name, name);
    temp->rate = rate;
    temp->hours = hours;
    temp->left = temp->right = NULL;
    temp->next = NULL;
    return temp;
}

void pushHead(int rate, const char *name, int hours)
{
    Game *newGame = createStd(name, rate, hours);
    if (!head)
    {
        head = tail = newGame;
    }
    else
    {
        newGame->next = head;
        head = newGame;
    }
}

void pushTail(int rate, const char *name, int hours)
{
    Game *newGame = createStd(name, rate, hours);
    if (!tail)
    {
        head = tail = newGame;
    }
    else
    {
        tail->next = newGame;
        tail = newGame;
    }
}

void priorityByRate(int rate, const char *name, int hours)
{
    if (!head || rate > head->rate)
    {
        pushHead(rate, name, hours);
    }
    else if (rate <= tail->rate)
    {
        pushTail(rate, name, hours);
    }
    else
    {
        Game *newGame = createStd(name, rate, hours);
        Game *curr = head;

        while (curr && curr->next->rate > newGame->rate)
        {
    
            curr = curr->next;
        }

        newGame->next = curr->next;
        curr->next = newGame;
    }
}

void popHeadName(const char *name)
{
    if (!head)
    {
        return;
    }
    else if (head == tail)
    {
        free(head);
        head = tail = NULL;
    }
    else
    {
        Game *del = head;
        head = head->next;
        free(del);
        del = NULL;
    }
}

void popTailName(const char *name)
{
    if (!tail)
    {
        return;
    }
    else if (head == tail)
    {
        free(tail);
        tail = head = NULL;
    }
    else
    {
        Game *curr = head;
        while (curr && strcmpi(curr->next->name, tail->name) != 0)
        {
            curr = curr->next;
        }
        curr->next = NULL;
        free(tail);
        tail = curr;
    }
}

void popByName(const char *name)
{
    if (strcmpi(name, head->name) == 0)
    {
        popHeadName(name);
    }
    else if (strcmpi(name, tail->name) == 0)
    {
        popTailName(name);
    }
    else
    {
        Game *curr = head;
        while (curr && strcmpi(curr->next->name, name) != 0)
        {
            curr = curr->next;
        }
        if (!curr)
        {
            printf("Data not found\n");
            return;
        }
        Game *del = curr->next;
        curr->next = del->next;
        free(del);
        del = NULL;
    }
}

void view(Game *curr)
{
    if (!curr)
    {
        return;
    }
    view(curr->left);
    printf("| %3d | %-15s | %-15d | %-15d |\n", i, curr->name, curr->rate, curr->hours);
    i++;
    view(curr->right);
}

Game *insertStd(Game *curr, Game *newNode)
{
    if (!curr)
    {
        return newNode;
    }
    else if (strcmpi(newNode->name, curr->name) > 0)
    {
        curr->left = insertStd(curr->left, newNode);
    }
    else if (strcmpi(newNode->name, curr->name) < 0)
    {
        curr->right = insertStd(curr->right, newNode);
    }
}

int searchStd(Game *curr, Game *newNode)
{
    if (!curr)
    {
        return 0;
    }
    else if (strcmpi(newNode->name, curr->name) == 0)
    {
        // strcpy(curr->nim, newNode->nim);
        curr->rate = newNode->rate;
        return 1;
    }
    else if (strcmpi(newNode->name, curr->name) > 0)
    {
        searchStd(curr->left, newNode);
    }
    else if (strcmpi(newNode->name, curr->name) < 0)
    {
        searchStd(curr->right, newNode);
    }
}

Game *deleteStd(Game *curr, const char *name)
{
    if (!curr)
    {
        printf("Cannot delete because Game name does not exist\n");
        return curr;
    }
    else if (strcmpi(name, curr->name) > 0)
    {
        curr->left = deleteStd(curr->left, name);
    }
    else if (strcmpi(name, curr->name) < 0)
    {
        curr->right = deleteStd(curr->right, name);
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
            strcpy(curr->name, temp->name);
            // strcpy(curr->nim, temp->nim);
            curr->rate = temp->rate;
            curr->hours = temp->hours;
            curr->left = deleteStd(curr->left, temp->name);
        }
        popByName(name);
        printf("Successfully Deleted Game\n");
    }

    return curr;
}

void viewByRate()
{
    Game *curr = head;

    if (!root)
    {
        printf("No data\n");
    }
    else
    {
        printf("================================================================\n");
        printf("| %3s | %-15s | %-15s | %-15s |\n", "No", "Name", "Rating", "Play Hours");
        printf("================================================================\n");
        while (curr)
        {
            printf("| %3d | %-15s | %-15d | %-15d |\n", i, curr->name, curr->rate, curr->hours);
            curr = curr->next;
            i++;
        }
        
        printf("================================================================\n");
    }
}

void viewStd()
{
    if (!root)
    {
        printf("No data\n");
    }
    else
    {
        printf("================================================================\n");
        printf("| %3s | %-15s | %-15s | %-15s |\n", "No", "Name", "Rating", "Play Hours");
        printf("================================================================\n");
        view(root);
        printf("================================================================\n");
    }
}

int checkName(const char *name){
    if(strlen(name) >= 1 && strlen(name) <= 100){
        for(int i = 0; i < strlen(name); i++){
            if(ispunct(name[i]) != 0){
                return 0;
            }
        }
    }else{
        return 0;
    }
    return 1;
}

int checkRate(const char *rate){
    char temp[100] = {};
    int res;
    if(strlen(rate) >= 1 && strlen(rate) <= 2){
        if(strlen(rate) == 1){
            if(isdigit(rate[0]) == 1){
                temp[0] = rate[0];
            }
        }else if(strlen(rate) == 2){
            if(isdigit(rate[0]) == 1 && isdigit(rate[1]) == 1){
                temp[0] = rate[0];
                temp[1] = rate[1];
            }
        }
        res = atoi(temp);
        if(res >= 1 && res <= 10){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
    return 0;
}

int checkHours(const char *hours){
    char temp[100] = {};
    int res;
    if(strlen(hours) >= 1 && strlen(hours) <= 4){
        if(strlen(hours) == 1){
            if(isdigit(hours[0]) == 1){
                temp[0] = hours[0];
            }else{
                return 0;
            }
        }else if(strlen(hours) == 2){
            if(isdigit(hours[0]) == 1 && isdigit(hours[1]) == 1){
                temp[0] = hours[0];
                temp[1] = hours[1];
            }else{
                return 0;
            }
        }else if(strlen(hours) == 3){
            if(isdigit(hours[0]) == 1 && isdigit(hours[1]) == 1 && isdigit(hours[2]) == 1){
                temp[0] = hours[0];
                temp[1] = hours[1];
                temp[2] = hours[2];
            }else{
                return 0;
            }
        }else if(strlen(hours) == 4){
            if(isdigit(hours[0]) == 1 && isdigit(hours[1]) == 1 && isdigit(hours[2]) == 1 && isdigit(hours[3]) == 1){
                temp[0] = hours[0];
                temp[1] = hours[1];
                temp[2] = hours[2];
                temp[3] = hours[3];
            }else{
                return 0;
            }
        }
        res = atoi(temp);
        printf("res: %d\n", res);
        if(res >= 0 && res <= 2000){
            return 1;
        }else{
            return 0;
        }
    }else{
        return 0;
    }
    return 0;
}

void addStd()
{
    char name[200] = {};
    char rate[100] = {};
    char hours[100] = {};
    int resRate;
    int resHours;
    do
    {
        printf("Name: ");
        scanf("%[^\n]", name);
        getchar();
    } while (checkName(name) == 0);

    do
    {
        printf("Rating: ");
        scanf("%[^\n]", rate); getchar();
        // fflush(stdin);
        // printf("%d\n", checkRate(rate));
    } while (checkRate(rate) == 0);
    resRate = atoi(rate);

    do
    {
        printf("Played Hours: ");
        scanf("%[^\n]", hours);
        getchar();
        printf("%d\n", checkHours(hours));
    } while (checkHours(hours) == 0);
    resHours = atoi(hours);

    if (searchStd(root, createStd(name, resRate, resHours)) == 1)
    {
        printf("Game name already exists! updated Rating instead.\n");
        popByName(name);
        searchStd(root, createStd(name, resRate, resHours));
    }
    else
    {
        root = insertStd(root, createStd(name, resRate, resHours));
    }
    priorityByRate(resRate, name, resHours);
    printf("Succes insert Game\n");
}

void remove()
{
    char name[200] = {};

    viewStd();
    do
    {
        printf("Insert Name you want to delete: ");
        scanf("%[^\n]", name);
        getchar();
    } while (strlen(name) < 1 || strlen(name) > 100);
    root = deleteStd(root, name);
}

int main()
{

    //	root = insertStd(root, createStd("mika", "12345"));
    //	root = insertStd(root, createStd("bijo", "12345"));
    //	root = insertStd(root, createStd("Grace", "12345"));
    //	root = insertStd(root, createStd("ryan", "12345"));
    //	root = insertStd(root, createStd("marlin", "12345"));
    //	searchStd(root, createStd("marlin", "23456"));
    //	root = deleteStd(root, "awddaw");
    //	view(root);

    int n;

    do
    {
        i=1;
        viewStd();
        printf("Menu\n");
        printf("1. view by rating\n");
        printf("2. Insert\n");
        printf("3. Delete\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            i = 1;
            viewByRate();
            break;
        case 2:
            addStd();
            break;
        case 3:
            i = 1;
            remove();
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (n != 4);

    return 0;
}
