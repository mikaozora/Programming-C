#include <stdio.h>
#include <string.h>

int playlistCount = 0;

struct songList
{
    char name[101];
    char artist[101];
    int duration;
};

struct playlist
{
    char name[100];
    int songCount;
    struct songList songs[50];
} list[50];

int search(char *playListName)
{
    if (playlistCount == 0)
    {
        return -1;
    }
    int left = 0;
    int right = playlistCount - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (strcmp(list[mid].name, playListName) == 0)
        {
            return mid;
        }
        else if (strcmp(list[mid].name, playListName) == 1)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

void swapPlaylist(int a, int b)
{
    playlist temp = list[a];
    // strcpy(list[a].name, list[b].name);
    list[a] = list[b];
    list[b] = temp;
}

int partition(char *pivot, int low, int high)
{
    int i = low - 1;
    int j = low;

    while (j < high)
    {
        if (strcmp(list[j].name, pivot) < 0)
        {
            i++;
            swapPlaylist(i, j);
        }
        j++;
    }
    swapPlaylist(i + 1, high);
    return i + 1;
}

void quickSortPlaylist(int low, int high)
{
    char pivot[100];
    if (low < high)
    {
        strcpy(pivot, list[high].name);
        int part = partition(pivot, low, high);
        quickSortPlaylist(low, part - 1);
        quickSortPlaylist(part + 1, high);
    }
}

void add()
{
    char songName[255];
    char artistName[255];
    int duration;
    char playlistName[255];

    printf("Input song name: ");
    scanf("%[^\n]", songName);
    getchar();
    printf("Input artis name: ");
    scanf("%[^\n]", artistName);
    getchar();
    printf("Input song duration: ");
    scanf("%d", &duration);
    getchar();
    printf("Input playlist name: ");
    scanf("%[^\n]", playlistName);
    getchar();

    if (search(playlistName) == -1)
    {
        strcpy(list[playlistCount].name, playlistName);
        playlistCount++;
    }
    quickSortPlaylist(0, playlistCount - 1);
}

void viewAll()
{
    for (int i = 0; i < playlistCount; i++)
    {
        printf("%s Playlist\n", list[i].name);
    }
}

int main()
{
    FILE *file;
    file = fopen("songs.txt", "r");
    int n;
    do
    {
        printf("Song Player\n====================\n");
        printf("1. Add new song\n");
        printf("2. Show all song\n");
        printf("3. Search song\n");
        printf("4. Exit\n");
        printf(">> ");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case 1:
            add();
            break;
        case 2:
            viewAll();
            break;
        case 3:
            break;
        case 4:
            break;
        default:
            break;
        }
    } while (n != 4);

    fclose(file);
}