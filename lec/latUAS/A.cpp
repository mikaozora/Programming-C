#include <stdio.h>

int main()
{
    int length;
    scanf("%d", &length);
    long long int arr[length + 1] = {};
    for (int i = 0; i < length; i++)
    {
        scanf("%lld", &arr[i]);
    }
    long long int m;
    scanf("%lld", &m);
    long long int f, fl = 0;
    for(int x = length-1; x >= 0; x--){
        for(int k = length - 1; k >= 0; k--){
            f = 0;  
            if(x+k-1 < length){
                for(int j = k; j >= 1; j--){
                    f += arr[x+k-j]*j;
                    if(f <= m && fl <= f){
                        fl = f;
                    }
                }
            }
        }
    }
    printf("%d\n", fl);
}