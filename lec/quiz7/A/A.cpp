#include <stdio.h>

int main(){
    FILE *file;
    file = fopen("testdata.in", "r");
    int a,b;
    fscanf(file, "%d %d", &a, &b);
    printf("%d\n", a+b);
    fclose(file);
}