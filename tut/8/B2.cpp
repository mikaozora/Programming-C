#include <stdio.h>
long long seat[5000];


void quickSort(long long seat[], int left, int right)
{
    int i = left, j = right;
    long long tmp;
    long long pivot = seat[(left + right) / 2];

   
    while (i <= j)
    {
        while (seat[i] < pivot)
            i++;
        while (seat[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = seat[i];
            seat[i] = seat[j];
            seat[j] = tmp;
            i++;
            j--;
        }
    };

   
    if (left < j)
        quickSort(seat, left, j);
    if (i < right)
        quickSort(seat, i, right);
}
int main()
{
    int q;
    scanf("%d", &q);

    int n;
    for (int i = 0; i < q; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%lld", &seat[j]);
        }

        quickSort(seat, 0, n - 1);

        long long maks = 0;
        for (int j = 1; j < n / 2; j++)
        {
            if (j == 1)
            {
                maks = seat[j] - seat[j - 1];
            }
            else
            {
                if (seat[j] - seat[j - 1] > maks)
                    maks = seat[j] - seat[j - 1];
            }
        }
        for (int j = n / 2 + 1; j < n; j++)
        {
            if (seat[j] - seat[j - 1] > maks)
                maks = seat[j] - seat[j - 1];
        }

        printf("Case #%d: %d\n", i + 1, maks);
    }
}