#include <stdio.h>
#include <string.h>

struct mahasiswa
{
    char name[101];
    char nim[10];
    long long int age;
    char code[7];
    char place[101];
    char date[101];
    char highSchool[101];
    long long int sibling;
    long long int height;
    char bank[10];
}mhs;


int main(){
    int n;
    scanf("%d", &n); getchar();
    for(int i = 0; i < n; i++){
        scanf("%[^\n]", mhs.name); getchar();
        scanf("%s", mhs.nim); getchar();
        scanf("%lld", &mhs.age); getchar();
        scanf("%s", mhs.code); getchar();
        scanf("%[^\n]", mhs.place); getchar();
        scanf("%[^\n]", mhs.date); getchar();
        scanf("%[^\n]", mhs.highSchool); getchar();
        scanf("%lld", &mhs.sibling); getchar();
        scanf("%lld", &mhs.height); getchar();
        scanf("%s", mhs.bank); getchar();

        printf("Mahasiswa ke-%d:\n", i+1);
        printf("Nama: %s\n", mhs.name);
        printf("NIM: %s\n", mhs.nim);
        printf("Umur: %lld\n", mhs.age);
        printf("Kode Pos: %s\n", mhs.code);
        printf("Tempat Lahir: %s\n", mhs.place);
        printf("Tanggal Lahir: %s\n", mhs.date);
        printf("Almamater SMA: %s\n", mhs.highSchool);
        printf("Jumlah Saudara Kandung: %lld\n", mhs.sibling);
        printf("Tinggi Badan: %lld\n", mhs.height);
        printf("NOMOR REKENING: %s\n", mhs.bank);
    }
    
}