#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int length;
    for(int i = 1; i <= n; i++){
        scanf("%d", &length);
        int count = 0;
        long long int arr[10001] = {};
        for(int j = 0; j < length; j++){
            scanf("%lld", &arr[j]);
        }
        int x = arr[0];
        for(int j = 1; j < length; j++){
            if(x == arr[j]){
                count++;
                x = arr[j+1];
                j++;
            }else{
                x = arr[j];
            }
        }
        printf("Case #%d: %d\n", i, count);
    }
}
    // int n;
    // int length;
    // scanf("%d", &n);
    // for (int i = 1; i <= n; i++)
    // {
    //     int count = 0;
    //     int him = 0;
    //     scanf("%d", &length);
    //     long long int arr[10001] = {};
    //     int index[10001] = {};
    //     for (int j = 0; j < length; j++)
    //     {
    //         scanf("%d", &arr[j]);
    //         index[arr[j]]++;
    //     }
    //     for (int j = 0; j < 10001; j++)
    //     {
    //         him = index[j] / 2;
    //         if (him > 0)
    //         {
    //             count += him;
    //         }
    //     }
    //     printf("Case #%d: %d\n", i, count);
    // } cara mika waktu uts