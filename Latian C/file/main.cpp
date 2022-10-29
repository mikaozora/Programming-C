#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fileOutput;
    fileOutput = fopen("text.txt", "w");
    int temp;
    scanf("%d", &temp);
    fprintf(fileOutput, "number: %d\n", temp);
    while (temp != 0)
    {
        scanf("%d", &temp);
        fprintf(fileOutput, "number: %d\n", temp);
    }

    fclose(fileOutput);

    FILE *fileInput;
    char a[50];
    char b[50];
    fileInput = fopen("text.txt", "r");
    while (fscanf(fileInput, "%s %s", a, b) != EOF)
    {
        printf("%s %s\n", a, b);
    }
    fclose(fileInput);
    
    FILE *testFile;
    testFile = fopen("text2.txt", "w");
    int c, d;
    scanf("%d %d", &c, &d);
    fprintf(testFile, "%d %d", c, d);
    fclose(testFile);

    FILE *fileResult;
    fileResult = fopen("text2.txt", "r");
    int num1, num2;
    fscanf(fileResult, "%d %d", &num1, &num2);
    printf("result: %d\n", num1 + num2);
}