#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

struct Food
{
    char name[100];
    int price;
};

struct Heap{
    Food *foods;
    int capacity;
    int lastIndex;
}heap;

void initHeap(){
    heap = {NULL, 2, 1};
    heap.foods = (Food*)malloc(sizeof(Food) * heap.capacity);
    return;
}

void resize(){
    heap.capacity = 2;
    heap.foods = (Food*)realloc(heap.foods, sizeof(Food) * heap.capacity);
}

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
    if (left < size && heap.foods[left].price > heap.foods[largest].price) //maxheap, minheap ganti menjadi <
    {
        largest = left;
    }
    if (right < size && heap.foods[right].price > heap.foods[largest].price) //maxheap
    {
        largest = right;
    }

    if (largest != curr)
    {
        swap(&heap.foods[largest], &heap.foods[curr]);
        heapify(largest, size);
    }
    return;
}

void buildHeap()
{
    for (int i = heap.lastIndex / 2; i >= 1; i--)
    {
        heapify(i, heap.lastIndex);
    }
}

void insertFood(const char *name, int price)
{
    if(heap.lastIndex == heap.capacity){
        resize();
    }
    strcpy(heap.foods[heap.lastIndex].name, name);
    heap.foods[heap.lastIndex].price = price;
    heap.lastIndex++;
    buildHeap();
}

void view()
{
    for (int i = 1; i < heap.lastIndex; i++)
    {
        printf("%s - %d\n", heap.foods[i].name, heap.foods[i].price);
    }
}

int searchFood(int price)
{
    for (int idx = 1; idx < heap.lastIndex; idx++)
    {
        if (heap.foods[idx].price == price)
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

    swap(&heap.foods[idx], &heap.foods[heap.lastIndex - 1]);
    heap.lastIndex--;
    buildHeap();
}

void heapSort(){
    buildHeap();
    for(int i = heap.lastIndex - 1; i > 1; i--){
        swap(&heap.foods[1], &heap.foods[i]);
        heapify(1, i);
    }
    return;
}

int main()
{
    initHeap();
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