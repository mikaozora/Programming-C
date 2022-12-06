#include <stdio.h>
#define LL long long

void sortValue(LL *array, LL low, LL high)
{
    if (low < high)
    {
        LL middle = low + (high - low) / 2, i, j, k;
        sortValue(array, low, middle); sortValue(array, middle + 1, high);
        LL leftSize = middle - low + 1, rightSize = high - middle, leftArray[leftSize], rightArray[rightSize];
        for (i = 0; i < leftSize; i++) leftArray[i] = array[low + i];
        for (j = 0; j < rightSize; j++) rightArray[j] = array[middle + 1 + j];
        i = 0, j = 0, k = low;
        while (i < leftSize && j < rightSize)
        {
            if (leftArray[i] <= rightArray[j]) { array[k] = leftArray[i]; i++; }
            else { array[k] = rightArray[j]; j++; } k++;
        }
        while (i < leftSize) { array[k] = leftArray[i]; i++; k++; }        
        while (j < rightSize) { array[k] = rightArray[j]; j++; k++; }
    }
}
LL searchValue(LL *array, LL size, LL start, LL target, LL pivot)
{
    LL left = start, right = size - 1;
    while (left <= right)
    {
        LL middle = (right + left) / 2, temp = target - pivot;
        if (temp <= 0) return 0;
        if (array[middle] == temp && array[middle] > pivot) return 1;
        if (array[middle] > temp) right = middle - 1;
        else left = middle + 1;
    }
    return 0;
}
int main()
{
    int input, i; scanf("%d", &input); getchar();
    for (i = 1; i <= input; i++)
    {
        LL number; scanf("%lld", &number); getchar();
        LL values[number], j, last = 0, count = 0;
        for (j = 0; j < number; j++) scanf("%lld", &values[j]);
        LL target; scanf("%lld", &target); getchar();
        sortValue(values, 0, number - 1);
        for (j = 0; j < number; j++)
        {
            if (values[j] == last) continue;
            if (target - values[j] <= 0) break;
            count += searchValue(values, number, j, target, values[j]);
            last = values[j];
        }
        printf("Case #%d: %lld\n", i, count);
    }
}