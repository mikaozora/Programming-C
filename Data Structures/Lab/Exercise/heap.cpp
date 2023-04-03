#include <stdio.h>
#include <string.h>
#define MAX 100

struct Food
{
    char name[100];
    int price;
} foods[MAX];

int lastIndex = 1;

void swap(Food *a, Food *b)
{
    Food temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int curr, int size)
{
    int left = 2 * curr;
    int right = left + 1;

    int largest = curr;
    if (left < size && foods[left].price > foods[largest].price) //maxheap, minheap ganti menjadi <
    {
        largest = left;
    }
    if (right < size && foods[right].price > foods[largest].price) //maxheap
    {
        largest = right;
    }

    if (largest != curr)
    {
        swap(&foods[largest], &foods[curr]);
        heapify(largest, size);
    }
    return;
}

void buildHeap()
{
    for (int i = lastIndex / 2; i >= 1; i--)
    {
        heapify(i, lastIndex);
    }
}

void insertFood(const char *name, int price)
{
    strcpy(foods[lastIndex].name, name);
    foods[lastIndex].price = price;
    lastIndex++;
    buildHeap();
}

void view()
{
    for (int i = 1; i < lastIndex; i++)
    {
        printf("%s - %d\n", foods[i].name, foods[i].price);
    }
}

int searchFood(int price)
{
    for (int idx = 1; idx < lastIndex; idx++)
    {
        if (foods[idx].price == price)
        {
            return idx;
        }
    }
    return -1;
}

void deleteFood(int price)
{
    int idx = searchFood(price);

    if (idx == -1)
    {
        return;
    }

    swap(&foods[idx], &foods[lastIndex - 1]);
    lastIndex--;
    buildHeap();
}

void heapSort(){
    buildHeap();
    for(int i = lastIndex-1; i > 1; i--){
        swap(&foods[1], &foods[i]);
        heapify(1, i);
    }
    return;
}

int main()
{
    insertFood("ayam", 32000);
    insertFood("baso", 30000);
    // view();
    printf("\n");
    insertFood("sate", 38000);
    view();
    // deleteFood(38000);
    printf("\n");
    heapSort();
    view();
    return 0;
}