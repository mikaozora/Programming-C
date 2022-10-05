#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int n;
    char input[100];
    char userId[6][100] = {"christ0208", "jordywa", "haku", "elior", "cleo", "cleo"};
    char name[6][100] = {"Christhoper", "Jordy", "Haku", "Eleanor", "Cleo Deus", "test"};
    char email[6][100] = {"chris@gmail.com", "jordy@gmail.com", "haku@gmail.com", "el@gmail.com", "cleo@gmail.com", "test@gmail.com"};
    int friendList[6];
    int lastFriend = 0;
    int length = sizeof(userId) / sizeof(userId[0]);

    int resultIndex[6];
    int remove = 0;
    do
    {
        int no = 1;
        int resultCount = 0;
        printf("Friendster CLI\n");
        printf("==============\n");
        printf("1. Add New Friend\n");
        printf("2. Unfriend\n");
        printf("3. Exit\n");
        printf("%d--\n", lastFriend);
        printf(">> ");
        scanf("%d", &n);
        switch (n)
        {
        case 1:
            printf("search friends by id: ");
            scanf("%s", input);
            getchar();
            for (int i = 0; i < length; i++)
            {
                if (strcmpi(input, userId[i]) == 0 || strstr(strlwr(name[i]), strlwr(input)) != NULL)
                {
                    printf("%d. %s\t|%s\t|%s\t|\n", no, userId[i], name[i], email[i]);
                    no++;
                    resultIndex[resultCount] = i;
                    resultCount++;
                }
            }
            if (resultCount == 1)
            {
                char answer[4];
                printf("Do you want to add this friend? [yes|no]: ");
                scanf("%s", answer);
                getchar();
                if (strcmpi("yes", answer) == 0)
                {
                    friendList[lastFriend] = resultIndex[0];
                    lastFriend++;
                }
            }
            if (resultCount > 1)
            {
                int choice = 0;
                printf("pick which friend you want [type 0 to exit]: ");
                scanf("%d", &choice);
                getchar();
                if (choice == 0)
                {
                    break;
                }
                else
                {
                    friendList[lastFriend] = resultIndex[choice - 1];
                    lastFriend++;
                }
            }
            break;
        case 2:
            for (int i = 0; i < lastFriend; i++)
            {
                printf("%d. %s\t|%s\t|%s\t\n", no, userId[friendList[i]], name[friendList[i]], email[friendList[i]]);
                no++;
            }
            printf("remove friend: ");
            scanf("%d", &remove);
            getchar();
            if (remove == 0)
            {
                break;
            }
            else
            {

                for (int i = remove - 1; i < lastFriend; i++)
                {
                    friendList[i] = friendList[i + 1];
                }
                lastFriend--;
            }
            break;
        case 3:
            break;
        default:
            printf("please input a valid number\n");
            break;
        }
    } while (n != 3);
}