#include <stdio.h>
#include <string.h>

int main()
{
    FILE *file;
    file = fopen("testdata.in", "r");
    int test, change;
    fscanf(file, "%d\n", &test);
    for (int i = 1; i <= test; i++)
    {
        char str[101] = {};
        char index[128] = {};
        char indexCount[128] = {};
        char alpha1, alpha2;
        fscanf(file, "%s\n", str);
        int length = strlen(str);
        fscanf(file, "%d\n", &change);
        for (int y = 0; y < change; y++)
        {
            fscanf(file, "%c %c\n", &alpha1, &alpha2);
            if(index[alpha1] > 0){
                continue;
            }
            for (int z = 0; z < length; z++)
            {
                if (str[z] == alpha1)
                {
                    index[str[z]] = 1;
                    str[z] = alpha2;
                    // indexCount[str[z]]++;
                }
                // printf("-%s-\n", str);
            }
            index[alpha1] = 1;
        }
        for(int y = 0; y < length; y++){
            indexCount[str[y]]++;
        }
        for (int y = 0; y < 127; y++)
        {
            if (indexCount[y] > 0)
            {
                printf("%c %d\n", y, indexCount[y]);
            }
        }
        // printf("%s", str);
    }
    fclose(file);
}