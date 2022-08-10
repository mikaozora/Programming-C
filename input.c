#include <stdio.h>
#include <string.h>

// int main(){
//     char nisn[10];
//     char firstName[30];
//     char lastName[30];
//     int usia;
//     int a, b;
//     scanf("%d%d", &a, &b); getchar();
//     printf("%d dan %d\n", a, b);
    
//     printf("masukkan nim kamu: ");
//     scanf("%[^\n]", nisn); getchar();
//     printf("masukkan nama awal kamu: ");
//     scanf("%[^\n]", firstName); getchar();
//     printf("masukkan nama akhir kamu: ");
//     scanf("%[^\n]", lastName); getchar();
//     printf("berapa usia kamu: ");
//     scanf("%d", &usia);

//     printf("Namamu adalah %s \n", strcat(firstName, lastName));
//     printf("kamu berusia %d tahun", usia);
// }

// rata rata raport

int main(){
    double mat, bindo, bing, progdas, fisika, result;
    printf("Masukkan nilai matematika: ");
    scanf("%lf", &mat);
    printf("Masukkan nilai bahasa indonesia: ");
    scanf("%lf", &bindo);
    printf("Masukkan nilai bahasa inggris: ");
    scanf("%lf", &bing);
    printf("Masukkan nilai pemrograman dasar: ");
    scanf("%lf", &progdas);
    printf("Masukkan nilai fisika: ");
    scanf("%lf", &fisika);
    result = (mat + bindo + bing + progdas + fisika) / 5;
    printf("Rata-rata nilai kamu adalah: %.2lf", result);
}