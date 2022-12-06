#include <stdio.h>

int binarySearch(int *arr, int length, int req)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == req)
        {
            return mid;
        }
        else if (arr[mid] < req)
        {
            left = mid + 1;
        }
        else if (arr[mid] > req)
        {
            right = mid - 1;
        }
        else
        {
            break;
        }
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];

    int j = low;
    while (j < high)
    {

        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
        j++;
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int height[n] = {};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &height[i]);
    }
    quickSort(height, 0, n - 1);
    int test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++)
    {
        int search;
        scanf("%d", &search);
        int index = binarySearch(height, n, search);
        printf("%d\n", (index != -1 ? index + 1 : -1));
    }
}