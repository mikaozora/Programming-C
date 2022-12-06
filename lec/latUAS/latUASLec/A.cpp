#include <stdio.h>
#include <string.h>

struct karyawans
{
    char id[25];
    char nama[256];
    double ipk;
    char role[255];
}karyawan[100];


int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++){
        scanf("%[^\n]", karyawan[i].id); getchar();
        // printf("%s\n", karyawan[i].id);
        scanf("%[^\n]", karyawan[i].nama); getchar();
        // printf("%s\n", karyawan[i].nama);
        scanf("%lf", &karyawan[i].ipk); getchar();
        // printf("%.2lf\n", karyawan[i].ipk);
        scanf("%[^\n]", karyawan[i].role); getchar();
        // printf("%s\n", karyawan[i].role);
    }
    char req[256] = {};
    double reqIpk;
    int count = 0;
    scanf("%[^\n]", req); getchar();
    // printf("%s\n", req);
    // printf("%s\n", karyawan[0].role);
    // printf("%d\n", strcmp(req, karyawan[0].role));
    scanf("%lf", &reqIpk); getchar();
    for(int i = 0; i < n; i++){
        if(strcmp(req, karyawan[i].role) == 0 && karyawan[i].ipk >= reqIpk){
            // printf("%s\n", karyawan[i].nama);
            count++;
        }
    }
    printf("count : %d\n", count);
}