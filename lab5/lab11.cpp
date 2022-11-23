#include <iostream>
using namespace std;
class Heap
{
protected:
    T *elements;
    int capacity;
    int count;

public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[] elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }

private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

// Your code here

template <class T>
int Heap<T>::getItem(T item)
{
    // TODO: return the index of item in heap
    // If item is not in heap, return -1
    for (int i = 0; i < count; i++)
    {
        if (elements[i] == item)
        {
            return i;
        }
    }
    return -1;
}

template <class T>
void Heap<T>::remove(T item)
{
    // TODO: remove the element with value equal to item
    // If item is not in heap, do nothing
    int index = getItem(item);
    if (index != -1)
    {
        elements[index] = elements[count - 1];
        count--;
        reheapDown(index);
    }

}

template <class T>
void Heap<T>::clear()
{
    // TODO: delete all elements in heap
    count = 0;  

}
int main()
{
    Heap<int> maxHeap;
    int arr[] = {78, 67, 32, 56, 8, 23, 19, 45};
    for (int i = 0; i < 8; i++)
        maxHeap.push(arr[i]);
    maxHeap.remove(78);
    maxHeap.printHeap();
}