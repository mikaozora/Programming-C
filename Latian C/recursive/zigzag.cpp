#include <stdio.h>

int arr[100] = {};
bool cek[100] = {};

void zigzag(int n, int length)
{
    if (n >= length)
    {
        for (int j = 1; j < length - 1; j++)
        {
            for (int k = 0; k < length; k++)
            {
                printf("%d", arr[k]);
            }
            printf("\n");
            printf("--%d %d--\n", arr[j], arr[j - 1]);
            printf("-+%d %d+-\n", arr[j], arr[j + 1]);
            if ((arr[j] > arr[j - 1] && arr[j] > arr[j + 1]) || (arr[j] < arr[j - 1] && arr[j] < arr[j + 1]))
            {
                printf("next-----\n");
                for (int i = 0; i < length; i++)
                {
                    printf("%d", arr[i]);
                }
                printf("\n");
            }
        }
    }
    else
    {
        for (int i = 1; i <= length; i++)
        {
            if (!cek[i])
            {
                cek[i] = true;
                arr[n] = i;
                zigzag(n + 1, length);
                cek[i] = false;
            }
        }
    }
}

int main()
{
    int length;
    scanf("%d", &length);
    zigzag(0, length);
}