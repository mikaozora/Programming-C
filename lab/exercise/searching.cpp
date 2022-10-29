#include <stdio.h>

void linearSearch(int *arr, int length, int req)
{
    bool res = false;
    int found;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == req)
        {
            res = true;
            printf("data found %d in index %d\n", arr[i], i);
        }
    }
    if (!res)
    {
        printf("data not found\n");
    }
}

// must sort
void binarySearch(int *arr, int length, int req)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid] == req)
        {
            printf("data found %d in index %d\n", req, mid);
            break;
        }
        else if (arr[mid] < req)
        {
            left = mid + 1;
        }
        else if (arr[mid] > req)
        {
            right = mid - 1;
        }
    }
}

void interPolationSearch(int *arr, int length, int req)
{
    int left = 0;
    int right = length - 1;

    while (left <= right)
    {
        int mid = left + ((right - left) * (req - arr[left]) / (arr[right] - arr[left]));
        if (arr[mid] == req)
        {
            printf("data found %d in index %d\n", req, mid);
            break;
        }
        else if (arr[mid] < req)
        {
            left = mid + 1;
        }
        else if (arr[mid] > req)
        {
            right = mid - 1;
        }
    }
}

int main()
{
    int arr[] = {10, 20, 30, 40, 40, 50, 60};
    int length = sizeof(arr) / sizeof(arr[0]);
    int req;
    scanf("%d", &req);
    linearSearch(arr, length, req);
    printf("-----------------\n");
    binarySearch(arr, length, req);
    printf("-----------------\n");
    interPolationSearch(arr, length, req);
}