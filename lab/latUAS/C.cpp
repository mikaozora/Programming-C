#include <stdio.h>

void swap(double *a, double *b)
{
    double temp = *a;
    *a = *b;
    *b = temp;
}

int partition(double arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
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
    return i + 1;
}

void sort(double arr[], int low, int high)
{
    if (low < high)
    {
        int part = partition(arr, low, high);
        sort(arr, low, part - 1);
        sort(arr, part + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    double length;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lf", &length);
        int length2 = (int)length;
        double arr[length2 + 5] = {};
        for (int j = 1; j <= length2; j++)
        {
            scanf("%lf", &arr[j]);
        }
        sort(arr, 1, length2);
        float index1 = 0;
        float index2 = 0;
        float index3 = 0;
        index1 = (length+1)/4;
        index2 = 2*(length+1)/4;
        index3 = 3*(length+1)/4;
        float q1 = (arr[(int)index1] * (1-(index1 - (int)index1))) + (arr[(int)index1+1] * (1-(1-(index1 - (int)index1))));
        float q2 = (arr[(int)index2] * (1-(index2 - (int)index2))) + (arr[(int)index2+1] * (1-(1-(index2 - (int)index2))));
        float q3 = (arr[(int)index3] * (1-(index3 - (int)index3))) + (arr[(int)index3+1] * (1-(1-(index3 - (int)index3))));
        printf("Case #%d: %.2f %.2f %.2f\n", i,q1, q2, q3);
    }
}