#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr;
    int n;
    scanf("%d", &n);
    // ptr = (int*) malloc(n * sizeof(int));
    // ptr = (int*) calloc (n, sizeof(int));

    if (ptr == NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    else
    {
        printf("Memory Allocated\n");
        for (int i = 0; i < n * 5; i++)
        {
            ptr[i] = i + 2;
        }
        printf("Value: ");
        for (int i = 0; i < n * 5; i++)
        {
            printf("%d ", ptr[i]);
        }
        printf("\n%d", sizeof(ptr));
        free(ptr);
        printf("\n%d", sizeof(ptr));
        printf("\nPtr successfully free\n");
    }
}