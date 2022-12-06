#include <stdio.h>

int start = 1;
long long int sum = 0;

void bitString(long long int arr[], int index, int length, int maxLength)
{
    if(index == maxLength){
        return;
    }
    else if (length > maxLength)
    {
        start++;
        bitString(arr, index+1, start, maxLength);
    }
    else
    {
        for (int i = index; i < length; i++)
        {
            // printf("%d ", arr[i]);
            sum += arr[i];
        }
        // printf("\n");
        bitString(arr, index, length + 1, maxLength);
    }
}

int main()
{
    int length;
    scanf("%d", &length);
    long long int arr[length + 1] = {};
    for (int i = 0; i < length; i++)
    {
        scanf("%lld", &arr[i]);
    }
    bitString(arr, 0, start, length);
    printf("%lld\n", sum);
}

