#include <stdio.h>

int main(){
    char name1[101], name2[101];
    int umur1, umur2;
    double height1, height2;
    scanf("%s %lf %d %s %lf %d", name1, &height1, &umur1, name2, &height2, &umur2);
    printf("Name 1: %s\n", name1);
    printf("Height 1: %.2lf\n", height1);
    printf("Age 1: %d\n", umur1);
    printf("Name 2: %s\n", name2);
    printf("Height 2: %.2lf\n", height2);
    printf("Age 2: %d\n", umur2);
}