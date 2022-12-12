#include <stdio.h>
#include <string.h>

struct courses{
    char name[100];
    int sks;
};

struct students
{
    char nim[10];
    char name[50];
    float ipk;
    struct courses course;
} s1, S2;

int main()
{
    s1.ipk = 3.5;
    strcpy(s1.name, "Yesun");
    strcpy(s1.nim, "1234554");
    strcpy(s1.course.name, "OOP");
    s1.course.sks = 4;

    printf("IPK: %.2f\n", s1.ipk);
    printf("Name : %s\n", s1.name);
    printf("course name & ipk : %s & %d\n", s1.course.name, s1.course.sks);
    printf("NIM : %s\n\n", s1.nim);
    S2.ipk = 4;
    strcpy(S2.name, "Hoooooo");
    strcpy(S2.nim, "76543");
    strcpy(S2.course.name, "Ds");
    S2.course.sks = 2;

    printf("IPK: %.2f\n", S2.ipk);
    printf("Name : %s\n", S2.name);
    printf("course name & ipk : %s & %d\n", S2.course.name, S2.course.sks);
    printf("NIM : %s\n", S2.nim);
}