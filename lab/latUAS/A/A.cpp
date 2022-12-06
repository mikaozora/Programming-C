#include <stdio.h>
#include <string.h>

struct students
{
    char name[100];
    float count;
    float score[101];
    float avg;
} student[10000];

int search(int length, char str[])
{
    int left = 0;
    int right = length - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (strcmp(student[mid].name, str) == 0)
        {
            return mid;
        }
        else if (strcmp(str, student[mid].name) < 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    FILE *file;
    file = fopen("testdata.in", "r");
    fscanf(file, "%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%[^\n]\n", student[i].name);
        fscanf(file, "%f", &student[i].count);
        for (int j = 0; j < student[i].count; j++)
        {
            fscanf(file, "%f", &student[i].score[j]);
            student[i].avg += student[i].score[j];
        }
        fgetc(file);
        student[i].avg /= student[i].count;
    }
    int m;
    fscanf(file, "%d\n", &m);
    for (int i = 1; i <= m; i++)
    {
        char str[101] = {};
        fscanf(file, "%[^\n]\n", str);
        int index = search(n, str);
        printf("Case #%d: ", i);
        if (index == -1)
        {
            printf("Invalid Name\n");
        }
        else
        {
            printf("%.2f\n", student[index].avg);
        }
    }

    fclose(file);
}