#include <stdio.h>

float calculateSum(float num[], int length);
void sumNumbers(int num[][2]);

int main()
{
    // array 1 dimensi
    // int arr[] = {10,20,30,40,50};
    // printf("%d\n", sizeof(arr) / sizeof(int));
    // for(int i = 0; i < 5; i++){
    //     printf("%d\n", arr[i]);
    // }

    //array string
    // char arr[][100] = {"mika", "joni", "agus", "john", "doeeeeeeeeeeeee"};
    // printf("%d", sizeof(arr)/sizeof(arr[0]));
    // for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++){
    //     printf("%s\n", arr[i]);
    // }

    //array 2 dimensi
    // int arr[4][5] = {{0, 1, 2, 3, 2}, {4, 5, 6, 7, 2}, {8, 9, 10, 11, 2}, {12, 13, 14, 15, 2}};
    // printf("%d\n", sizeof(arr) / sizeof(arr[0])); //rows
    // printf("%d\n", sizeof(arr[0]) / sizeof(int)); //column
    // printf("%d\n", (sizeof(arr) / sizeof(arr[0])) * (sizeof(arr[0]) / sizeof(int))); //total
    // for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    // {
    //     for (int j = 0; j < sizeof(arr[0]) / sizeof(int); j++)
    //     {
    //         printf("arr[%d][%d] = %d\n", i, j, arr[i][j]);
    //     }
    // }

    //array 3 dimensi
    // int arr[2][2][2] = { {{0, 1}, {2, 3}}, {{4, 5}, {6, 7}} };
    // printf("%d", arr[1][1][1]);
    // for(int i = 0; i < 2; i++){
    //     for(int j = 0; j < 2; j++){
    //         for(int k = 0; k < 2; k++){
    //             printf("arr[%d][%d][%d] = %d\n", i, j, k, arr[i][j][k]);
    //         }
    //     }
    // }

    //array function
    // float result, num[] = {22.5, 22.5, 20, 40, 51.3};
    // int length = sizeof(num)/sizeof(num[0]);
    // result = calculateSum(num, length);
    // printf("jumlah: %.2f", result);

    //array multi dimensi function
    int num[3][2];
    printf("masukkan angka: ");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            scanf("%d", &num[i][j]);
        }
    }
    sumNumbers(num);
}

float calculateSum(float num[], int length)
{
    float sum = 0;
    // printf("%d", sizeof(num)/sizeof(num[0]));
    for (int i = 0; i < length; i++)
    {
        sum += num[i];
    }
    return sum;
}

void sumNumbers(int num[][2])
{
    printf("-------------------\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%d\n", num[i][j]);
        }
    }
}