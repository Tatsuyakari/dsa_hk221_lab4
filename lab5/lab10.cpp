#include <iostream>
using namespace std;
void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < numberOfElements && maxHeap[left] > maxHeap[largest])
        largest = left;
    if (right < numberOfElements && maxHeap[right] > maxHeap[largest])
        largest = right;
    if (largest != index)
    {
        swap(maxHeap[index], maxHeap[largest]);
        reheapDown(maxHeap, numberOfElements, largest);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    int parent = (index - 1) / 2;
    if (parent >= 0 && maxHeap[parent] < maxHeap[index])
    {
        swap(maxHeap[parent], maxHeap[index]);
        reheapUp(maxHeap, numberOfElements, parent);
    }
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    reheapDown(arr, size, 0);
    cout << "[ ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "]";
}