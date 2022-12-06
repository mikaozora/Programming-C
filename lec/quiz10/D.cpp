#include <stdio.h>
#include <string.h>

void swap(char *a, char *b){
    char temp[101] = {};
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);

}
int partition(char arr[][101], int low, int high){
    char pivot[256] = {};
    strcpy(pivot, arr[high]);
    int i = low-1;
    int j = low;
    while(j < high){
        if(strcmp(arr[j], pivot) < 0){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void sort(char arr[][101],int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        sort(arr, low, part-1);
        sort(arr, part+1, high);
    }
}



int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i<= n; i++){
        int count, req;
        scanf("%d %d", &count, &req);
        char name[100][101] = {};
        for(int j = 0; j < count; j++){
            scanf("%s", name[j]);
        }
        sort(name, 0, count-1);
        // for(int j = 0; j < count; j++){
        //     printf("%s\n", name[j]);
        // }
        for(int j = 0; j < count; j++){
            if(strcmp(name[req-1], name[j]) == 0){
                printf("Case #%d: %s\n", i, name[j]);
            }
        }
    }
}