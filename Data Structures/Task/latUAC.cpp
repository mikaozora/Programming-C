#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int found;
int number;

struct Player
{
    char username[100];
    char job[100];
    int score, height;
    float winrate;
    struct Player *left, *right;
} *root = NULL, *temp;

int max(int a, int b)
{
    return (a > b ? a : b);
}

int getHeight(struct Player *curr)
{
    if (!curr)
    {
        return 0;
    }
    return curr->height;
}
int getBf(Player *curr)
{
    if (!curr)
    {
        return 0;
    }
    return getHeight(curr->left) - getHeight(curr->right);
}

Player *rightRotation(Player *t)
{
    Player *s = t->left;
    Player *b = s->right;
    t->left = b;
    s->right = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));
    return s;
}
Player *leftRotation(Player *t)
{
    Player *s = t->right;
    Player *b = s->left;
    t->right = b;
    s->left = t;

    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    s->height = 1 + max(getHeight(s->left), getHeight(s->right));
    return s;
}
Player *createPlayer(const char *username, const char *job, int score, float winrate)
{
    temp = (Player *)malloc(sizeof(Player));
    strcpy(temp->username, username);
    strcpy(temp->job, job);
    temp->score = score;
    temp->winrate = winrate;
    temp->height = 1;
    temp->left = temp->right = NULL;
    return temp;
}

Player *insertPlayer(Player *curr, Player *newPlayer)
{
    if (!curr)
    {
        return newPlayer;
    }
    else if (newPlayer->score < curr->score)
    {
        curr->left = insertPlayer(curr->left, newPlayer);
    }
    else if (newPlayer->score > curr->score)
    {
        curr->right = insertPlayer(curr->right, newPlayer);
    }
    else
    {
        if (newPlayer->winrate < curr->winrate)
        {
            curr->left = insertPlayer(curr->left, newPlayer);
        }
        else if (newPlayer->winrate >= curr->winrate)
        {
            curr->right = insertPlayer(curr->right, newPlayer);
        }
        else
        {
            return curr;
        }
    }
    
    curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    printf("%d\n", curr->height);
    
    int bf = getBf(curr);
    // LL
    if (bf > 1 && getBf(curr->left) >= 0)
    {
        return rightRotation(curr);
    }
    // RR
    if (bf < -1 && getBf(curr->right) <= 0)
    {
        return leftRotation(curr);
    }

    // LR
    if (bf > 1 && getBf(curr->left) < 0)
    {
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }

    // RL
    if (bf < -1 && getBf(curr->right) > 0)
    {
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }
    return curr;
}

void display(Player *curr)
{
    if (!curr)
    {
        // printf("skip");
        return;
    }
    display(curr->left);
    printf("%s %d %.2f\n", curr->username, curr->score, curr->winrate);
    display(curr->right);
}

Player *deletePlayer(Player *curr, int score)
{
    if (!curr)
    {
        return NULL;
    }
    else if (score < curr->score)
    {
        curr->left = deletePlayer(curr->left, score);
    }
    else if (score > curr->score)
    {
        curr->right = deletePlayer(curr->right, score);
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
            Player *del = curr;
            curr = curr->left;
            free(del);
            del = NULL;
        }
        else if (!curr->left)
        {
            Player *del = curr;
            curr = curr->right;
            free(del);
            del = NULL;
        }
        else
        {
            Player *temp = curr->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            curr->score = temp->score;
            strcpy(curr->username, temp->username);
            curr->winrate = temp->winrate;
            strcpy(curr->job, temp->job);
            curr->left = deletePlayer(curr->left, temp->score);
        }
    }

    // curr->height = 1 + max(getHeight(curr->left), getHeight(curr->right));
    // printf("%d\n", curr->height);
    
    int bf = getBf(curr);
    // LL
    if (bf > 1 && getBf(curr->left) >= 0)
    {
        return rightRotation(curr);
    }
    // RR
    if (bf < -1 && getBf(curr->right) <= 0)
    {
        return leftRotation(curr);
    }

    // LR
    if (bf > 1 && getBf(curr->left) < 0)
    {
        curr->left = leftRotation(curr->left);
        return rightRotation(curr);
    }

    // RL
    if (bf < -1 && getBf(curr->right) > 0)
    {
        curr->right = rightRotation(curr->right);
        return leftRotation(curr);
    }
    return curr;
}

void findPlayer(Player *curr, int score)
{
    if (!curr)
    {
        return;
    }
    else if (score < curr->score)
    {
        findPlayer(curr->left, score);
    }
    else if (score > curr->score)
    {
        findPlayer(curr->right, score);
    }
    else
    {
        found = 1;
        findPlayer(curr->left, score);
        printf("%d %s [%s] (%.2f%%)\n", number, curr->username, curr->job, curr->winrate);
        number++;
        findPlayer(curr->right, score);
    }
}

char *generateJob(int job)
{
    char temp[100] = {};
    if (job == 0)
    {
        sprintf(temp, "%s", "Novice");
    }
    else if (job == 1)
    {
        sprintf(temp, "%s", "Warrior");
    }
    else if (job == 2)
    {
        sprintf(temp, "%s", "Sniper");
    }
    else if (job == 3)
    {
        sprintf(temp, "%s", "Wizard");
    }
    else if (job == 4)
    {
        sprintf(temp, "%s", "Druid");
    }
    else if (job == 5)
    {
        sprintf(temp, "%s", "Assassin");
    }
    return temp;
}

void insertMenu()
{
    char username[100] = {};
    char jobstr[100] = {};
    int job, score, match, win, lose, draw;
    float winrate = 0;
    scanf("%[^#]#%d#%d#%d#%d#%d#%d", username, &job, &score, &match, &win, &lose, &draw);
    getchar();
    winrate = ((float)win / (float)match) * 100;
    strcpy(jobstr, generateJob(job));
    root = insertPlayer(root, createPlayer(username, jobstr, score, winrate));
}

struct tempPlayer
{
    char username[100];
    char job[100];
    int score, height;
    float winrate;
} tempPlayers[999];
int currScore = -1;
int lastIndex = 0;

void showAllPlayer(Player *curr)
{

    if (curr)
    {
        showAllPlayer(curr->left);
        if (currScore == -1)
        {
            currScore = curr->score;
            lastIndex = 0;
        }
        if (currScore != curr->score)
        {
            printf("Score %d\n", currScore);
            currScore = curr->score;
            for (int i = lastIndex-1; i >= 0; i--)
            {
                printf("%d. %s [%s] (%.0f%%)\n", lastIndex - i, tempPlayers[i].username, tempPlayers[i].job, tempPlayers[i].winrate);
            }
            lastIndex = 0;
        }
        if (currScore == curr->score)
        {
            tempPlayer temp;
            strcpy(temp.username, curr->username);
            strcpy(temp.job, curr->job);
            temp.winrate = curr->winrate;
            tempPlayers[lastIndex] = temp;
            lastIndex++;
        }
        showAllPlayer(curr->right);
    }
}

int main()
{
    // display(root);
//    root = insertPlayer(root, createPlayer("Gregor", "Warrior", 120, 50));
//    root = insertPlayer(root, createPlayer("Heimdall", "Wizzard", 130, 70));
//    root = insertPlayer(root, createPlayer("joel", "Warrior", 121, 60));
//    root = insertPlayer(root, createPlayer("apeng", "Warrior", 122, 60));
    
    root = insertPlayer(root, createPlayer("Gregor", "Sniper", 113, (float) 90));
    root = insertPlayer(root, createPlayer("Heimdall", "Druid", 300, (float) 50));
    root = insertPlayer(root, createPlayer("Travy", "Warrior", 300, (float) 50));
    root = insertPlayer(root, createPlayer("Treton", "Novice", 300, (float) 50));
    root = insertPlayer(root, createPlayer("Homer", "Druid", 113, (float) 80));
    root = insertPlayer(root, createPlayer("Garen", "Warrior", 113, (float) 70));
    
    // root = insertPlayer(root, createPlayer("A", "Warrior", 20, (float)70));
    // root = insertPlayer(root, createPlayer("B", "Warrior", 20, (float)60));
    // root = insertPlayer(root, createPlayer("c", "Warrior", 20, (float)50));
    // root = insertPlayer(root, createPlayer("d", "Warrior", 20, (float)40));
    // root = deletePlayer(root, 120);
    // display(root);

    int n, count, score;
    char input[100] = {};
    scanf("%d", &n);
    for (int j = 0; j < n; j++)
    {
        scanf("%s", input);
        getchar();
        if (strcmp("INSERT", input) == 0)
        {
            scanf("%d", &count);
            getchar();
            for (int i = 0; i < count; i++)
            {
                insertMenu();
            }
//            display(root);
        }
        else if (strcmp("FIND", input) == 0)
        {
            scanf("%d", &score);
            printf("Score %d\n", score);
            found = 0;
            number = 1;
            findPlayer(root, score);
            if (found == 0)
            {
                printf("No data found for %d\n", score);
            }
        }
        else if (strcmp("DELETE", input) == 0)
        {
            scanf("%d", &score);
            root = deletePlayer(root, score);
        }
        else if (strcmp("SHOWALL", input) == 0)
        {
            showAllPlayer(root);
            
            printf("Score %d\n", currScore);
            
            for (int i = lastIndex-1; i >= 0; i--)
            {
                printf("%d. %s [%s] (%.0f%%)\n", lastIndex - i, tempPlayers[i].username, tempPlayers[i].job, tempPlayers[i].winrate);
            }
            lastIndex = 0;
            currScore = -1;
        }
    }
    return 0;
}
