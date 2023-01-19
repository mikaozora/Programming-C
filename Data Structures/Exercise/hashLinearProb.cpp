#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxArrSize = 6;

struct data
{
    char heroName[20];
    char heroType[5];
    int lvl;
} *dataArr[maxArrSize];

int hashFunc(char heroName[])
{
    char first = heroName[0];
    char last = heroName[strlen(heroName) - 1];

    int res = (first + last) % maxArrSize;
    return res;
}
void insert(char const heroName[], char const heroType[], int lvl)
{
    struct data *temp = (struct data *)malloc(sizeof(struct data));
    strcpy(temp->heroName, heroName);
    strcpy(temp->heroType, heroType);
    temp->lvl = lvl;

    int index = hashFunc(temp->heroName);
    if (!dataArr[index])
    {
        dataArr[index] = temp;
    }
    else
    {
        int currIndex = index + 1;
        while (dataArr[currIndex])
        {
            currIndex++;
            if (currIndex >= maxArrSize)
            {
                currIndex = 0;
            }
            if (currIndex == index)
            {
                break;
            }
        }
        if (currIndex == index)
        {
            printf("Array is full\n");
        }
        else
        {
            dataArr[currIndex] = temp;
        }
    }
}

void display()
{
    for (int i = 0; i < maxArrSize; i++)
    {
        if (dataArr[i])
        {
            printf("%s %s %d\n", dataArr[i]->heroName, dataArr[i]->heroType, dataArr[i]->lvl);
        }
    }
}

int main()
{
    insert("invoker", "asg", 1);
    insert("invokes", "asg", 1);
    insert("invokegr", "asg", 1);
    insert("axe", "asg", 1);
    insert("sven", "asg", 1);
    insert("jilong", "asg", 1);
    insert("miya", "asg", 1);
    insert("fredrin", "asg", 1);
    display();
}