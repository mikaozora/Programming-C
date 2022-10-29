#include <stdio.h>

void convertBinary(long long int dec)
{
    if (dec == 0)
    {
        return;
    }
    convertBinary(dec / 2);
    printf("%lld", dec%2);
}

int main()
{
    long long int dec;
    scanf("%lld", &dec);
    convertBinary(dec);
}
