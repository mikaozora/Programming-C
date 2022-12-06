#include <stdio.h>

void quickSort(int arr[], int left, int right)
{
    int i = left, j = right;
    long long tmp;
    long long pivot = arr[(left + right) / 2];

   
    while (i <= j)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    };

   
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}
int lower_bound(int arr[], int N, int X)
{
    int mid;

  
    int low = 0;
    int high = N;

    
    while (low < high)
    {
        mid = low + (high - low) / 2;

    
        if (X <= arr[mid])
        {
            high = mid;
        }

       
        else
        {
            low = mid + 1;
        }
    }

  
    if (low < N && arr[low] < X)
    {
        low++;
    }

    
    return low;
}

int main()
{
    int n, m, x;
    scanf("%d", &n);

    int arr[100050];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, n - 1);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &x);
        if (x < arr[0] || x > arr[n - 1])
        {
            printf("-1\n");
            continue;
        }
        int found = lower_bound(arr, n - 1, x);
        if (found == -1)
            printf("-1\n");
        else
        {
            if (arr[found] != x)
                printf("-1\n");
            else
                printf("%d\n", found + 1);
        }
    }
}