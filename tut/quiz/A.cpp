#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int row, space;
        scanf("%d", &row);
        scanf("%d", &space);
        double arr[row][row];
        double avg1 = 0, avg2 = 0, avg3 = 0, avg4 = 0;
        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < row; k++)
            {
                scanf("%lf", &arr[j][k]);
            }
        }
        if (row - space == 0)
        {
            for (int j = 0; j < space; j++)
            {
                for (int k = 0; k < space; k++)
                {
                    avg1 += arr[j][k];
                }
            }
            avg1 /= space * space;
            printf("%.2lf\n", avg1);
        }
        else
        {
            for (int j = 0; j < space; j++)
            {
                for (int k = 0; k < space; k++)
                {
                    avg1 += arr[j][k];
                }
            }
            avg1 /= space * space;
            printf("%.2lf ", avg1);
            for (int j = 0; j < space; j++)
            {
                for (int k = row-space; k < row; k++)
                {
                    avg2 += arr[j][k];
                }
            }
            avg2 /= space * space;
            printf("%.2lf\n", avg2);
            for (int j = row-space; j < row; j++)
            {
                for (int k = 0; k < space; k++)
                {
                    avg3 += arr[j][k];
                }
            }
            avg3 /= space * space;
            printf("%.2lf ", avg3);
            for (int j = row-space; j < row; j++)
            {
                for (int k = row-space; k < row; k++)
                {
                    avg4 += arr[j][k];
                }
            }
            avg4 /= space * space;
            printf("%.2lf\n", avg4);
        }
    }
}