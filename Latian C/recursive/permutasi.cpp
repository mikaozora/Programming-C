#include <stdio.h>

int arr[100] = {};
bool cek[100];
int count = 0;

void permutasi(int n, int length)
{
    // printf("Permutasi(%d)\n", n);
    
    if (n >= length)
    {
        for (int i = 0; i < length; i++)
        {
            printf("%d", arr[i]);
        }
        printf("\n");
        count++;
    }
    else
    {
        for (int i = 1; i <= length; i++)
        {
            // printf("-%d-\n", i);
            if (!cek[i])
            {
                cek[i] = true;
                arr[n] = i;
                // printf("Cek : ");
                // for (int y = 1; y <= length; y++)
                // {
                //     printf("%d ", cek[y]);
                // }
                // printf("\n");

                // printf("arr : ");
                // for (int y = 0; y < length; y++)
                // {
                //     printf("%d ", arr[y]);
                // }
                // printf("\n");
                permutasi(n + 1, length);
                cek[i] = false;

                // printf("Permutasi(%d)\n", n);
                // printf("Cek : ");
                // for (int y = 1; y <= length; y++)
                // {
                //     printf("%d ", cek[y]);
                // }
                // printf("\n");
            }
        }
    }
}

int main()
{
    int length;
    scanf("%d", &length);
    permutasi(0, length);
    printf("Count: %d", count);
}