#include <stdio.h>
#include <stdlib.h>

struct course
{
    int score;
    char matkul[10];
} *crs;

int main()
{
    // struct course *crs;
    int n;
    scanf("%d", &n);
    crs = (struct course *)malloc(n * sizeof(crs));
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", (crs + i)->matkul, &(crs + i)->score);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%s %d\n", (crs + i)->matkul, (crs + i)->score);
    }
    free(crs);
}