#include <stdio.h>

int main()
{
    // int x,y,k;
    // scanf("%d %d", &x, &y);
    // scanf("%d", &k);
    // int res[35] = {};
    // res[0] = x;
    // res[1] = y;
    // for(int i = 2; i <= 5; i++){
    //     res[i] = res[i-1] + res[i-2];
    // }
    // printf("%d\n", res[k]);
    int a, b, n, temp;
    scanf("%d %d", &a, &b);
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        temp = a + b;
        a = b;
        b = temp;
    }
    printf("%d\n", b);
}