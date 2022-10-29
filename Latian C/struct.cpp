#include <stdio.h>
#include <string.h>

struct Person
{
    char name[50];
    int telepon;
    double salary;
} person1;

typedef struct mahasiswa
{
    struct Person per;
    int nim;
    double saku;
    char name[50];
} mhs;

struct dosen
{
    int id;
    char name[50];
    char gender[50];
} dos[10];


int main()
{
    strcpy(person1.name, "Joel Edward");
    person1.telepon = 123456798;
    person1.salary = 550000;
    printf("%s\n", person1.name);
    printf("%d\n", person1.telepon);
    printf("%.2lf", person1.salary);
    printf("--------------\n");

    mhs mhs1;
    strcpy(mhs1.name, "Mika Ozora");
    mhs1.nim = 12345;
    mhs1.saku = 2345;
    printf("%s\n", mhs1.name);
    printf("%d\n", mhs1.nim);
    printf("%.2lf", mhs1.saku);

    printf("--------------\n");
    mhs1.per.salary = 123444;
    printf("%.2lf\n", mhs1.per.salary);

    printf("--------------\n");
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &dos[i].id); getchar();
        scanf("%[^\n]", dos[i].name); getchar();
        scanf("%s", dos[i].gender); getchar();
    }

    for(int i = 0; i < n; i++){
        printf("%d\n", dos[i].id);
        printf("%s\n", dos[i].name);
        printf("%s\n", dos[i].gender);
    }

}