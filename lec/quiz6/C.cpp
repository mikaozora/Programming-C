#include <stdio.h>
#include <string.h>

struct familyStudents
{
    char father[101];
    char mother[101];
    int sibling;
};

struct students
{
    char code[35];
    char name[101];
    char gender[101];
    struct familyStudents fams;
};

struct lecture
{
    char code[35];
    char name[101];
    char gender[101];
    int countStudent;
    struct students stud[101];
} lec[101];

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        scanf("%s", lec[i].code);
        getchar();
        scanf("%[^\n]", lec[i].name);
        getchar();
        scanf("%[^\n]", lec[i].gender);
        getchar();
        scanf("%d", &lec[i].countStudent);
        getchar();
        for (int j = 0; j < lec[i].countStudent; j++)
        {
            scanf("%s", &lec[i].stud[j].code);
            getchar();
            scanf("%[^\n]", lec[i].stud[j].name);
            getchar();
            scanf("%[^\n]", lec[i].stud[j].gender);
            getchar();
            scanf("%[^\n]", lec[i].stud[j].fams.father);
            getchar();
            scanf("%[^\n]", lec[i].stud[j].fams.mother);
            getchar();
            scanf("%d", &lec[i].stud[j].fams.sibling);
            getchar();
        }
    }
    int req;
    scanf("%d", &req);
    getchar();
    printf("Kode Dosen: %s\n", lec[req - 1].code);
    printf("Nama Dosen: %s\n", lec[req - 1].name);
    printf("Gender Dosen: %s\n", lec[req - 1].gender);
    printf("Jumlah Mahasiswa: %d\n", lec[req - 1].countStudent);
    for (int j = 0; j < lec[req - 1].countStudent; j++)
    {
        printf("Kode Mahasiswa: %s\n", lec[req - 1].stud[j].code);
        printf("Nama Mahasiswa: %s\n", lec[req - 1].stud[j].name);
        printf("Gender Mahasiswa: %s\n", lec[req - 1].stud[j].gender);
        printf("Nama Ayah: %s\n", lec[req - 1].stud[j].fams.father);
        printf("Nama Ibu: %s\n", lec[req - 1].stud[j].fams.mother);
        printf("Jumlah Saudara Kandung: %d\n", lec[req - 1].stud[j].fams.sibling);
    }
}