#include <stdio.h>

struct mahasiswa
{
    char id[25];
    char name[101];
    int age;
}mhs[1001];


int main(){
    int n;
    scanf("%d", &n); getchar();
    for(int i = 0; i < n; i++){
        scanf("%[^\n]", mhs[i].id); getchar();
        // printf("%s\n", mhs[i].id);
        scanf("%[^\n]", mhs[i].name); getchar();
        // printf("%s\n", mhs[i].name);
        scanf("%d", &mhs[i].age); getchar();
        // printf("%d\n", mhs[i].age);
    }
    int t;
    scanf("%d", &t);
    for(int i = 1; i<=t; i++){
        int choose;
        scanf("%d", &choose);
        printf("Query #%d:\n", i);
        printf("ID: %s\n", mhs[choose-1].id);
        printf("Name: %s\n", mhs[choose-1].name);
        printf("Age: %d\n", mhs[choose-1].age);
    }
    
}