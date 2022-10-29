#include <stdio.h>

int hitung =0;

int fiboCount(int call)
{
    hitung++;
    int count;
    if (call == 0)
    {
        count = 0;
    }else if(call == 1){
        count = 1;
    }
    else
    {
        count = fiboCount(call-2) + fiboCount(call-1);
    }
    return count;
}

int main()
{
    int t, call;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        hitung = 0;
        scanf("%d", &call);
        fiboCount(call);
        printf("Case #%d: %d\n", i, hitung);
    }
}