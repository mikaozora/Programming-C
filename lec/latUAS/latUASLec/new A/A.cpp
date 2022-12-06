#include <stdio.h>
#include <string.h>

struct karyawans
{
    char Id[100];
    char name[256];
    char jurusan[256];
    float ipk;
    char role[256];
} karyawan[100], karyawan1[100], karyawan2[100], karyawan3[100];

int i = 0;
int count = 0;

void swap(int a, int b)
{
    karyawans temp;
    temp = karyawan[a];
    karyawan[a] = karyawan[b];
    karyawan[b] = temp;
}

int partitionDivisi(int low, int high)
{
    char pivot[256] = {};
    strcpy(pivot, karyawan[high].role);
    int i = low - 1;
    int j = low;
    while (j <= high)
    {
        if (strcmp(karyawan[j].role, pivot) < 0)
        {
            i++;
            swap(i, j);
        }
        j++;
    }
    swap(i + 1, high);
    return i + 1;
}

void sortDivisi(int low, int high)
{
    if (low < high)
    {
        int part = partitionDivisi(low, high);
        sortDivisi(low, part - 1);
        sortDivisi(part + 1, high);
    }
}

void swapJurusan(int a, int b)
{
    karyawans temp;
    temp = karyawan1[a];
    karyawan1[a] = karyawan1[b];
    karyawan1[b] = temp;
}

int partitionJurusan(int low, int high)
{
    char pivot[256] = {};
    strcpy(pivot, karyawan1[high].jurusan);
    int i = low - 1;
    int j = low;
    while (j <= high)
    {
        if (strcmp(karyawan[j].jurusan, pivot) < 0)
        {
            i++;
            swapJurusan(i, j);
        }
        j++;
    }
    swapJurusan(i + 1, high);
    return i + 1;
}

void sortJurusan(int low, int high)
{
    if (low < high)
    {
        int part = partitionJurusan(low, high);
        sortJurusan(low, part - 1);
        sortJurusan(part + 1, high);
    }
}

void swapIpk(int a, int b)
{
    karyawans temp;
    temp = karyawan2[a];
    karyawan2[a] = karyawan2[b];
    karyawan2[b] = temp;
}

int partitionIpk(int low, int high)
{
    float pivot = karyawan1[high].ipk;
    int i = low - 1;
    int j = low;
    while (j <= high)
    {
        if (karyawan[j].ipk < pivot)
        {
            i++;
            swapIpk(i, j);
        }
        j++;
    }
    swapIpk(i + 1, high);
    return i + 1;
}

void sortIpk(int low, int high)
{
    if (low < high)
    {
        int part = partitionIpk(low, high);
        sortIpk(low, part - 1);
        sortIpk(part + 1, high);
    }
}

int main()
{
    FILE *file;
    file = fopen("testdata.in", "r");
    while (!feof(file))
    {
        fscanf(file, "%[^#]#%[^#]#%[^#]#%f#%[^\n]\n", karyawan[i].Id, karyawan[i].name, karyawan[i].jurusan, &karyawan[i].ipk, karyawan[i].role);
        i++;
    }
    char req[256] = {};
    char divisi[256] = {};
    float ipk = 0;
    scanf("%[^\n]", req);
    getchar();
    scanf("%[^\n]", divisi);
    getchar();
    scanf("%f", &ipk);
    getchar();
    // for (int j = 0; j < i; j++)
    // {
    //     if (strcmp(karyawan[j].role, divisi) == 0 && strcmp(karyawan[j].jurusan, req) == 0 && karyawan[j].ipk >= ipk)
    //     {
    //         count++;
    //     }
    // }
    int index1 = 0;
    printf("%d\n", count);
    sortDivisi(0, i - 1);
    for (int j = 0; j < i; j++)
    {
        if (strcmp(divisi, karyawan[j].role) == 0)
        {
            karyawan1[index1] = karyawan[j];
            index1++;
            // printf("%s %s %s %.2f %s\n", karyawan[j].Id, karyawan[j].name, karyawan[j].jurusan, karyawan[j].ipk, karyawan[j].role);
        }
    }
    for(int j = 0; j < index1; j++){
        printf("%s %s %s %.2f %s\n", karyawan1[j].Id, karyawan1[j].name, karyawan1[j].jurusan, karyawan1[j].ipk, karyawan1[j].role);
    }
    printf("====================================================\n");
    sortJurusan(0, index1-1);
    int index2 = 0;
    for (int j = 0; j < index1; j++)
    {
        if (strcmp(req, karyawan1[j].jurusan) == 0)
        {
            karyawan2[index2] = karyawan1[j];
            index2++;
            // printf("%s %s %s %.2f %s\n", karyawan[j].Id, karyawan[j].name, karyawan[j].jurusan, karyawan[j].ipk, karyawan[j].role);
        }
    }
    for(int j = 0; j < index2; j++){
        printf("%s %s %s %.2f %s\n", karyawan2[j].Id, karyawan2[j].name, karyawan2[j].jurusan, karyawan2[j].ipk, karyawan2[j].role);
    }
    sortIpk(0, index2-1);
    int index3 = 0;
    // for (int j = 0; j < index2; j++)
    // {
    //     if (karyawan2[j].ipk >= ipk)
    //     {
    //         karyawan3[index3] = karyawan2[j];
    //         index3++;
    //         // printf("%s %s %s %.2f %s\n", karyawan[j].Id, karyawan[j].name, karyawan[j].jurusan, karyawan[j].ipk, karyawan[j].role);
    //     }
    // }
    for(int j = 0; j < index2; j++){
        printf("%s %s %s %.2f %s\n", karyawan2[j].Id, karyawan2[j].name, karyawan2[j].jurusan, karyawan2[j].ipk, karyawan2[j].role);
    }
    fclose(file);
}