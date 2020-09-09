#include <stdio.h>

int getLeftChildIndex(int index)
{
    return index * 2 + 1;
}

int getRightChildIndex(int index)
{
    return index * 2 + 2;
}

int getParentIndex(int index)
{
    return (index - 1) / 2;
}

void swap(int index1, int index2, int *arr)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}


void maxHeapify(int *arr, int size, int index)
{
    int largest = index;
    int left = getLeftChildIndex(index);
    int right = getRightChildIndex(index);
    if(left < size && arr[largest] < arr[left])
    {
        largest = left;
    }
    if(right < size && arr[largest] < arr[right])
    {
        largest = right;
    }
    if(largest != index)
    {
        swap(index, largest, arr);
        maxHeapify(arr, size, largest);
    }
}

void heapifyUp(int *arr, int index)
{
    int parent = getParentIndex(index);
    if(parent >= 0)
    {
        if(arr[parent] < arr[index])
        {
            swap(parent, index, arr);
            heapifyUp(arr, parent);
        }
    }
}

void addData(int *arr, int size, int data)
{
    arr[size-1] = data;
    heapifyUp(arr, size-1);
}

void buildMaxHeap(int *arr, int size)
{
    int lastNonLeafIndex = (size - 1) / 2;
    while(lastNonLeafIndex >= 0)
    {
        maxHeapify(arr, size, lastNonLeafIndex);
        lastNonLeafIndex--;
    }
}

void printHeap(int *arr, int size)
{
    int i = 0;
    while(i != size)
    {
        printf("%d ",arr[i++]);
    }
    printf("\n");
}

void heapSort(int *arr, int size)
{
    size = size - 1;
    for(int i=0; i<size; i++)
    {
        swap(0, size-i, arr);
        maxHeapify(arr, size-i, 0);
    }
}

int extractMax(int *arr, int size)
{
    int max = arr[0];
    swap(0, size-1, arr);
    size--;
    maxHeapify(arr, size, 0);
    return max;
}

int main()
{
    int arr[10] = {1,22,36,4,15,656,779,28,59};
    int size = 9;
    printHeap(arr, size);
    buildMaxHeap(arr, size);
    printHeap(arr, size);
    size++;
    addData(arr, size, 110);
    printHeap(arr, size);
    while(size != 0)
    {
         int max = extractMax(arr, size);
        printf("max = %d\n", max);
        size--;
    }
    return 0;
}
