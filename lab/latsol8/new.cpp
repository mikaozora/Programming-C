#include <stdio.h>
#include <string.h>

struct Song
{
    char name[100];
    char artist[100];
    int duration;
};

struct Playlist
{
    char name[100];
    struct Song songs[100];
    int songCount;
} playlists[100];

int playlistCount = 0;

int lookupExistingPlaylist(char lookupPlaylist[])
{
    // binary search
    // 1. left, right, mid
    int left = 0;
    int right = playlistCount - 1;
    int mid = 0;

    // 2. cari datanya sampai left > right
    while (left <= right)
    {
        mid = (left + right) / 2;
        // 2.1. cek datanya sama atau tidak
        if (strcmp(playlists[mid].name, lookupPlaylist) == 0)
        {
            return mid;
        }

        // 2.2. perkecil scope
        // 2.2.1. gerak ke kiri saat pencarian < nilai mid
        if (strcmp(lookupPlaylist, playlists[mid].name) < 0)
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
    Playlist temp = playlists[a];
    playlists[a] = playlists[b];
    playlists[b] = temp;
}

int partition(char *pivot, int low, int high){
    int i = low - 1;
    int j = low;

    while(j < high){
        if(strcmp(playlists[j].name, pivot) < 0){
            i++;
            swapPlaylist(i, j);
        }
        j++;
    }
    swapPlaylist(i + 1, high);
    return i+1;
}

void sortPlaylist(int low, int high){
    char pivot[100];
    if(low < high){
        strcpy(pivot, playlists[high].name);
        int part = partition(pivot, low, high);
        sortPlaylist(low, part - 1);
        sortPlaylist(part + 1, high);
    }
}

void swapSong(Song arr[], int a, int b){
    Song temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partitionSong(Song arr[], int low, int high){
    Song pivotSong = arr[high];
    int i = low - 1;
    int j = low;
    if(j < high){
        if(strcmp(arr[j].name, pivotSong.name) < 0){
            i++;
            swapSong(arr, i, j);
        }
        j++;
    }
    swapSong(arr, i + 1, high);
    return i+1;
}

void sortSong(Song arr[], int low, int high){
    
    if(low < high){
        int part = partitionSong(arr, low, high);
        sortSong(arr, low, part-1);
        sortSong(arr, part + 1, high);
    }
}

void merge(int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    Playlist arrLeft[leftSize], arrRight[rightSize];
    for(int i = 0; i < leftSize; i++){
        arrLeft[i] = playlists[i+left];
    }
    for(int i = 0; i < rightSize; i++){
        arrRight[i] = playlists[i + mid + 1];
    }
    int indexLeft = 0;
    int indexRight = 0;
    int index = left;

    while(indexLeft < leftSize && indexRight < rightSize){
        if(strcmp(arrLeft[indexLeft].name, arrRight[indexRight].name) < 0){
            playlists[index] = arrLeft[indexLeft];
            indexLeft++;
        }else{
            playlists[index] = arrRight[rightSize];
            indexRight++;
        }
        index++;
    }
    while(indexLeft < leftSize){
        playlists[index] = arrLeft[indexLeft];
        index++;
        indexLeft++;
    }
    while(indexRight < rightSize){
        playlists[index] = arrRight[indexRight];
        index++;
        indexRight++;
    }
}

void mergeSort(int left, int right){
    if(left == right){
        return;
    }
    int mid = (left + right) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void importSongData()
{
    // baca filenya dulu
    // 1. buka file nya
    FILE *fd = fopen("songs.txt", "r");

    // 2. baca isi file nya sampai selesai (EOF)
    while (!feof(fd))
    {
        // 2.1. ambil datanya menggunakan fscanf
        char songname[100];
        char songartist[100];
        int songduration;
        char playlistname[100];
        fscanf(fd, "%[^#]#%[^#]#%d#%[^\n]\n", songname, songartist, &songduration, playlistname);

        // 2.2. masukkin datanya ke dalam variable dari struct yang terbuat
        // 2.2.0. cek apakah sudah ada playlist yang dibaca
        Playlist newPlaylist;
        int searchIndex = lookupExistingPlaylist(playlistname);
        if (searchIndex != -1)
        {
            // ambil playlist yang ada
            newPlaylist = playlists[searchIndex];
        }
        else
        {
            // 2.2.1. masukkin data playlist dulu
            strcpy(newPlaylist.name, playlistname);
            newPlaylist.songCount = 0;
        }

        // 2.2.2. masukkin data song nya ke dalam playlist
        Song newSong;
        strcpy(newSong.name, songname);
        strcpy(newSong.artist, songartist);
        newSong.duration = songduration;

        newPlaylist.songs[newPlaylist.songCount] = newSong;
        newPlaylist.songCount++;

        // 2.2.3. masukkin playlist baru ke dalam data playlist yang dipunyai
        if (searchIndex == -1)
        {
            playlists[playlistCount] = newPlaylist;
            playlistCount++;
        }
        else
        {
            playlists[searchIndex] = newPlaylist;
        }
    }
    fclose(fd);
}

void viewAll()
{
    // sortPlaylist(0, playlistCount - 1);
    mergeSort(0, playlistCount-1);
    // looping untuk print playlist
    for (int i = 0; i < playlistCount; i++)
    {
        printf("%s\n", playlists[i].name);

        // setiap playlist yang ada, print song nya
        for (int j = 0; j < playlists[i].songCount; j++)
        {
            printf("\t%s - %s - %d\n", playlists[i].songs[j].name, playlists[i].songs[j].artist, playlists[i].songs[j].duration);
        }
    }
}

void insertMenu()
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
    Playlist newPlaylist;
    int searchIndex = lookupExistingPlaylist(playlistName);

    if(searchIndex != -1){
        newPlaylist = playlists[searchIndex];

    }else{
        strcpy(newPlaylist.name, playlistName);
        newPlaylist.songCount = 0;
    }
    Song newSong;
    strcpy(newSong.name, songName);
    strcpy(newSong.artist, artistName);
    newSong.duration = durations;

    int indexSong = newPlaylist.songCount;
    newPlaylist.songs[indexSong] = newSong;
    newPlaylist.songCount++;
    sortSong(newPlaylist.songs, 0, newPlaylist.songCount - 1);
    if(searchIndex == -1){
        playlists[playlistCount] = newPlaylist;
        playlistCount++;
    }else{
        playlists[searchIndex] = newPlaylist;
    }
    sortPlaylist(0, playlistCount-1);
}



int main()
{
    importSongData();
    viewAll();
    insertMenu(); 
    viewAll();
    return 0;
}
