#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct songs
{
    char name[256];
    char artist[256];
    int duration;
};

struct playlists
{
    char name[256];
    int songCount;
    struct songs song[100];
} playlist[100];

int playlistCount = 0;

void menu()
{
    printf("Song Player\n====================\n");
    printf("1. Add new song\n");
    printf("2. Show all song\n");
    printf("3. Search song\n");
    printf("4. Exit\n");
    printf(">> ");
}

int searchPlaylist(char *playlistName)
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
        if (strcmp(playlist[mid].name, playlistName) == 0)
        {
            return mid;
        }
        else if (strcmp(playlist[mid].name, playlistName) > 0)
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



void swapPlaylist(int a, int b){
    playlists temp = playlist[a];
    playlist[a] = playlist[b];
    playlist[b] = temp;
}

int partition(char *pivot, int low, int high){
    int i = low-1;
    int j = low;
    while(j < high){
        if(strcmp(playlist[j].name, pivot) < 0){
            i++;
            swapPlaylist(i, j);
        }
        j++;
    }
    swapPlaylist(i+1, high);
    return i+1;
}

void sortPlaylist(int low, int high){
    char pivot[255];
    if(low < high){
        strcpy(pivot, playlist[high].name);
        int part = partition(pivot, low, high);
        sortPlaylist(low, part-1);
        sortPlaylist(part+1, high);
    }
}

void swapSongs(songs arr[], int a, int b){
    songs temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partitionSong(songs arr[], int low, int high){
    char pivot[256];
    strcpy(pivot, arr[high].name);
    int i = low-1;
    int j = low;
    if(j < high){
        if(strcmp(arr[j].name, pivot) < 0){
            i++;
            swapSongs(arr, i, j);
        }
        j++;
    }
    swapSongs(arr, i+1, high);
    return i+1;
}

void sortSongs(songs arr[], int low, int high){
    if(low < high){
        int part = partitionSong(arr, low, high);
        sortSongs(arr, low, part-1);
        sortSongs(arr, part+1, high);
    }
}

void importData()
{
    FILE *file;
    file = fopen("songs.txt", "r");
    char playlistName[256];
    char songName[256];
    char artistName[256];
    int durations;
    while (!feof(file))
    {
        fscanf(file, "%[^#]#%[^#]#%d#%[^\n]\n", songName, artistName, &durations, playlistName);
        int index = searchPlaylist(playlistName);
        int indexSong;
        playlists newPlaylist;
        if(index != -1){
            newPlaylist = playlist[index];
        }else{
            strcpy(newPlaylist.name, playlistName);
            newPlaylist.songCount = 0;
        }
        songs newSong;
        indexSong = newPlaylist.songCount;
        strcpy(newSong.name, songName);
        strcpy(newSong.artist, artistName);
        newSong.duration = durations;
        newPlaylist.song[indexSong] = newSong;
        newPlaylist.songCount++;
        sortSongs(newPlaylist.song, 0, newPlaylist.songCount-1);
        if(index == -1){
            playlist[playlistCount] = newPlaylist;
            playlistCount++;
        }else{
            playlist[index] = newPlaylist;
        }
        sortPlaylist(0, playlistCount-1);
        // if (index == -1)
        // {
        //     strcpy(playlist[playlistCount].name, playlistName);
        //     indexSong = playlist[playlistCount].songCount;
        //     strcpy(playlist[playlistCount].song[indexSong].name, songName);
        //     strcpy(playlist[playlistCount].song[indexSong].artist, artistName);
        //     playlist[playlistCount].song[indexSong].duration = durations;
        //     playlist[playlistCount].songCount++;
        //     playlistCount++;
        // }
        // else
        // {
        //     indexSong = playlist[index].songCount;
        //     strcpy(playlist[index].song[indexSong].name, songName);
        //     strcpy(playlist[index].song[indexSong].artist, artistName);
        //     playlist[index].song[indexSong].duration = durations;
        //     playlist[index].songCount++;
        // }
    }
}

void viewAll()
{
    sortPlaylist(0, playlistCount-1);
    for (int i = 0; i < playlistCount; i++)
    {
        printf("%s\n", playlist[i].name);
        for (int j = 0; j < playlist[i].songCount; j++)
        {
            printf("\t%s - %s - %d\n", playlist[i].song[j].name, playlist[i].song[j].artist, playlist[i].song[j].duration);
        }
    }
}

void add()
{
    char playlistName[256] = {};
    char songName[256] = {};
    char artistName[256] = {};
    int durations;
    int length;
    do
    {
        printf("Song Name [must not be empty]: ");
        scanf("%[^\n]", songName);
        getchar();
        length = strlen(songName);
    } while (length == 0);
    do
    {
        printf("Artist Name [must not be empty]: ");
        scanf("%[^\n]", artistName);
        getchar();
    } while (strlen(artistName) == 0);
    do
    {
        printf("Song duration [must more than 0]: ");
        scanf("%d", &durations);
        getchar();
    } while (durations == 0);
    do
    {
        printf("Playlist Name [must not be empty]: ");
        scanf("%[^\n]", playlistName);
        getchar();
    } while (strlen(playlistName) == 0);
    playlists newPlaylist;
    int index = searchPlaylist(playlistName);
    int indexSong;

    if(index != -1){
        newPlaylist = playlist[index];
    }else{
        strcpy(newPlaylist.name, playlistName);
        newPlaylist.songCount = 0;
    }
    songs newSong;
    strcpy(newSong.name, songName);
    strcpy(newSong.artist, artistName);
    newSong.duration = durations;
    indexSong = newPlaylist.songCount;
    newPlaylist.song[indexSong] = newSong;
    newPlaylist.songCount++;
    sortSongs(newPlaylist.song, 0, newPlaylist.songCount-1);
    if(index == -1){
        playlist[playlistCount] = newPlaylist;
        playlistCount++;
    }else{
        playlist[index] = newPlaylist;
    }
    sortPlaylist(0, playlistCount-1);

    // if (index == -1)
    // {
    //     indexSong = playlist[playlistCount].songCount;
    //     strcpy(playlist[playlistCount].name, playlistName);
    //     strcpy(playlist[playlistCount].song[indexSong].name, songName);
    //     strcpy(playlist[playlistCount].song[indexSong].artist, artistName);
    //     playlist[playlistCount].song[indexSong].duration = durations;
    //     playlist[playlistCount].songCount++;
    //     playlistCount++;
    // }
    // else
    // {
    //     indexSong = playlist[index].songCount;
    //     strcpy(playlist[index].song[indexSong].name, songName);
    //     strcpy(playlist[index].song[indexSong].artist, artistName);
    //     playlist[index].song[indexSong].duration = durations;
    //     playlist[index].songCount++;
    // }
    // sortPlaylist(0, playlistCount-1);
}

void searchSong()
{
    char search[255] = {};
    printf("Search song: ");
    scanf("%[^\n]", search);
    getchar();
    for (int i = 0; i < playlistCount; i++)
    {
        bool check = false;
        for (int j = 0; j < playlist[i].songCount; j++)
        {
            if (strstr(playlist[i].song[j].name, search) != NULL)
            {
                if (!check)
                {
                    printf("%s\n", playlist[i].name);
                    check = true;
                }
                printf("\t%s - %s - %d\n", playlist[i].song[j].name, playlist[i].song[j].artist, playlist[i].song[j].duration);
            }
        }
    }
}

void save()
{
    FILE *file;
    file = fopen("songs.txt", "w");
    for (int i = 0; i < playlistCount; i++)
    {
        for (int j = 0; j < playlist[i].songCount; j++)
        {
            fprintf(file, "%s#%s#%d#%s\n", playlist[i].song[j].name, playlist[i].song[j].artist, playlist[i].song[j].duration, playlist[i].name);
        }
    }
}

int main()
{
    int n;
    importData();
    do
    {
        menu();
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
            searchSong();
            break;
        case 4:
            save();
            break;
        default:
            break;
        }
    } while (n != 4);
}