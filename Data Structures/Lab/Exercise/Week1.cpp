#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct students
{
    char name[256];
    int age;
} s1, s2[3];

void printsStudent(students s)
{
    printf("%d - %s, %d years old\n", &s, s.name, s.age);
}

int main()
{
    // pointer
    //  int a = 5;
    //  printf("Address of a: %d\n", &a);
    //  printf("value of a: %d\n", a);

    // int *b = &a;
    // *b = 10;
    // printf("Address of b: %d\n", b);
    // printf("value of b: %d\n", *b);

    // int **c = &b;
    // **c = 80;
    // printf("Address of c: %d\n", c);
    // printf("value of *c: %d\n", *c);
    // printf("value of **c: %d\n", **c);

    // array
    // int scores[] = {100, 98, 85, 80};
    // for(int i = 0; i < sizeof(scores)/sizeof(scores[0]); i++){
    //     printf("Value of index %d = %d with address %d\n", i, *(scores+i), (scores+i));
    // }

    strcpy(s1.name, "Budi");
    s1.age = 100;
    printsStudent(s1);
    char name[][100] = {"jul", "ed", "ward"};
    int ages[] = {15, 12, 10};
    for (int i = 0; i < 3; i++)
    {
        s2[i].age = ages[i];
        strcpy(s2[i].name, name[i]);
    }

    students *komti = &s2[1];
    strcpy(komti->name, "SHam");
    komti->age = 45;

    for (int i = 0; i < 3; i++)
    {
        printsStudent(s2[i]);
    }

    students *sp1[3];
    for(int i = 0; i < 3; i++){
        sp1[i] = (students*)malloc(sizeof(students));
        strcpy(sp1[i]->name, "haha");
        sp1[i]->age = 50;
    }
    for(int i = 0; i < 3; i++){
        printf("%d - %s, %d years old\n", &sp1[i], sp1[i]->name, sp1[i]->age);
    }
}