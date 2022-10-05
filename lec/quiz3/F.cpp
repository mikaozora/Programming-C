#include <stdio.h>

int main()
{
    int n, x, temp, max1 = 0, max2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        
        scanf("%d", &x);
        int arr[x];
        for (int j = 0; j < x; j++)
        {
            scanf("%d", &arr[j]);
        }
        max1 = arr[0];
        for (int j = 1; j < x; j++)
        {
            if (arr[j] > max1)
            {
                max2 = max1;
                max1 = arr[j];
                temp = j;
                // printf("%d+\n", max1);
            }else if(arr[j] > max2 && temp != j){
                max2 = arr[j];
            }
        }
        printf("Case #%d: %d\n", i + 1, max1 + max2);
        max2 = 0;
    }
}


// int main()
// {
//     int n, x, temp, max1, max2;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &x);
//         int arr[x];
//         for (int j = 0; j < x; j++)
//         {
//             scanf("%d", &arr[j]);
//         }
//         for (int k = 0; k < x; k++)
//         {
//             for (int l = k + 1; l < x; l++)
//             {
//                 if (arr[k] < arr[l])
//                 {
//                     temp = arr[l];
//                     arr[l] = arr[k];
//                     arr[k] = temp;
//                 }
//             }
//         }
//         printf("Case #%d: %d\n", i + 1, arr[0] + arr[1]);
//     }
// }