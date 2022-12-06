#include <stdio.h>

struct matakuliah
{
    char code[10];
    char name[101];
    int credit;
}matkul[1001];

int main(){
    int n;
    scanf("%d", &n); getchar();
    for(int i = 0; i < n; i++){
        scanf("%[^\n]", matkul[i].code); getchar();
        scanf("%[^\n]", matkul[i].name); getchar();
        scanf("%d", &matkul[i].credit); getchar();
    }
    int m;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        int req;
        scanf("%d", &req);
        printf("Query #%d:\n", i);
        printf("Code: %s\n", matkul[req-1].code);
        printf("Name: %s\n", matkul[req-1].name);
        printf("Credits: %d\n", matkul[req-1].credit);
    }
}