#include <stdio.h>

int main()
{
    FILE *file;
    file = fopen("testdata.in", "r");
    int test, n;
    fscanf(file, "%d\n", &test);
    for (int i = 1; i <= test; i++)
    {
        int cube[101] = {};
        int total = 0;
        int area = 0;
        int pMeter = 0;
        fscanf(file, "%d\n", &n);
        for (int y = 0; y < n; y++)
        {
            fscanf(file, "%d\n", &cube[y]);
            total += cube[y];
        }
        area = 4 * total;
        int all = 0;
        int intersect = 0;
        for (int y = 0; y < n; y++)
        {
            all += ((cube[y] * 2 * 4) - 2 * (cube[y] - 1) * 2);
        }
        for (int y = 0; y < n-1; y++)
        {
            if (cube[y] > cube[y + 1])
            {
                intersect += 4 * cube[y + 1];
            }
            else
            {
                intersect += 4 * cube[y];
            }
        }
        pMeter = all - intersect;
        printf("Case #%d: %d %d\n", i,pMeter, area);
    }

    fclose(file);
}