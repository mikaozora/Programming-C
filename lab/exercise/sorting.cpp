#include <stdio.h>

void ascBubbleSort() // false
{
    int arr[] = {5, 2, 1, 4, 3};
    int temp;
    int length = 5;
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1 + i; j < 5; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}

void descBubbleSort() // false
{
    int arr[] = {5, 2, 1, 4, 3};
    int temp;
    int length = 5;
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 1 + i; j < 5; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }
}

void ascInsertionSort()
{
    int arr[] = {5, 2, 1, 4, 3};
    int length = 5;
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 1; i < length; i++)
    {
        int temp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}

// void selectSort() // lab version
// {
//     int arr[5] = {5, 2, 1, 4, 3};
//     for (int i = 0; i < 5; i++)
//     {
//         int idxMin = -1;
//         for (int j = i; j < 5; j++)
//         {
//             if (j == i)
//             {
//                 idxMin = j;
//             }
//             else if (arr[j] < arr[idxMin])
//             {
//                 idxMin = j;
//             }
//         }
//         if (idxMin == i)
//         {
//         }
//         else
//         {
//             int temp = arr[i];
//             arr[i] = arr[idxMin];
//             arr[idxMin] = temp;
//         }
//     }
//     for (int i = 0; i < 5; i++)
//     {
//         printf("%d ", arr[i]);
//     }
// }

void selectionSort()
{
    int arr[] = {5, 2, 1, 4, 3};
    int length = 5;
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < length - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < length; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}

void newascBubbleSort()
{
    int arr[] = {5, 2, 1, 4, 3};
    int length = 5;
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int leftSize = mid - left + 1;
    int rightSize = right - mid;
    int arrLeft[leftSize];
    int arrRight[rightSize];

    for (int i = 0; i < leftSize; i++)
    {
        arrLeft[i] = arr[i + left];
    }
    for (int i = 0; i < rightSize; i++)
    {
        arrRight[i] = arr[i + mid + 1];
    }
    int indexLeft = 0;
    int indexRight = 0;
    int index = left;

    while (indexLeft < leftSize && indexRight < rightSize)
    {
        if (arrLeft[indexLeft] < arrRight[indexRight])
        {
            arr[index] = arrLeft[indexLeft];
            indexLeft++;
        }
        else
        {
            arr[index] = arrRight[indexRight];
            indexRight++;
        }
        index++;
    }
    while (indexLeft < leftSize)
    {
        arr[index] = arrLeft[indexLeft];
        index++;
        indexLeft++;
    }
    while (indexRight < rightSize)
    {
        arr[index] = arrRight[indexRight];
        index++;
        indexRight++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    // base
    if (left == right)
    {
        return;
    }
    // index tengah
    int mid = (left + right) / 2;

    // sub array kiri
    mergeSort(arr, left, mid);
    // sub array kanan
    mergeSort(arr, mid + 1, right);

    // process
    merge(arr, left, mid, right);
}

void printArr(int arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[], int low, int high)
{
    //     i
    //     5, 3, 2, 9, 10, [7] - pivot
    //     j
    int i = low - 1;
    int pivot = arr[high];

    // for(int j = low; j < high; j++){
    //     if(arr[j] <= pivot){
    //         i++;
    //         swap(&arr[i], &arr[j]);
    //     }
    // }
    int j = low;
    while (j < high)
    {

        printf("%d^ %d^\n", arr[i+1], arr[j]);
        if (arr[j] <= pivot)
        {
            i++;
            printf("%d+ %d-\n", arr[i], arr[j]);
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
    printf("\n------false ascending bubble sort--------\n");
    ascBubbleSort();
    printf("\n------false descending bubble sort--------\n");
    descBubbleSort();
    printf("\n------selection sort--------\n");
    selectionSort();
    printf("\n------Insertion sort--------\n");
    ascInsertionSort();
    printf("\n------new ascending bubble sort--------\n");
    newascBubbleSort();
    printf("\n-----------Merge Sort-----------------\n");
    int arr[] = {4, 1, 9, 5, 7};
    int length = sizeof(arr) / sizeof(arr[0]);
    printArr(arr, length);
    printf("\n");
    mergeSort(arr, 0, length - 1);
    printArr(arr, length);
    printf("\n-----------Quick Sort---------------\n");
    int arr2[] = {11, 12, 13, 9, 5, 7};
    int length2 = sizeof(arr2) / sizeof(arr2[0]);
    printArr(arr2, length2);
    printf("\n");
    quickSort(arr2, 0, length2 - 1);
    printArr(arr2, length2);
}