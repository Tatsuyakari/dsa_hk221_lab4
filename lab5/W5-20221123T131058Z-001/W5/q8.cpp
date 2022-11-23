#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
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
        delete[]elements;
    }
    void push(T item);

    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();

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
//Your code goes here
//Implement functions: Peek, Pop, Size, Empty, Contains to a maxHeap. If the function cannot execute, return -1.
template<class T>
int Heap<T>::size(){
    return count;
}

template<class T>
bool Heap<T>::isEmpty(){
    return count == 0;
}

template<class T>
T Heap<T>::peek(){
    if (count == 0) return -1;
    return elements[0];
}

template<class T>
bool Heap<T>::contains(T item){
    for (int i = 0; i < count; i++){
        if (elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (count == 0) return false;
    elements[0] = elements[count - 1];
    count--;
    reheapDown(0);
    return true;
}

template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count + 1);
    elements[count] = item;
    count++;
    reheapUp(count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity > capacity){
        T* old = elements;
        capacity = capacity * 2;
        elements = new T[capacity];
        for (int i = 0; i < count; i++){
            elements[i] = old[i];
        }
        delete[]old;
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position > 0){
        int parent = (position - 1) / 2;
        if (elements[position] > elements[parent]){
            T temp = elements[position];
            elements[position] = elements[parent];
            elements[parent] = temp;
            reheapUp(parent);
        }
    }
}

void reheapDown(int maxHeap[], int numberOfElements, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < numberOfElements && maxHeap[left] > maxHeap[largest]) {
        largest = left;
    }
    if (right < numberOfElements && maxHeap[right] > maxHeap[largest]) {
        largest = right;
    }
    if (largest != index) {
        int temp = maxHeap[index];
        maxHeap[index] = maxHeap[largest];
        maxHeap[largest] = temp;
        reheapDown(maxHeap, numberOfElements, largest);
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index) {
    if (index > 0) {
        int parent = (index - 1) / 2;
        if (maxHeap[index] > maxHeap[parent]) {
            int temp = maxHeap[index];
            maxHeap[index] = maxHeap[parent];
            maxHeap[parent] = temp;
            reheapUp(maxHeap, numberOfElements, parent);
        }
    }
}

template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    for (int i = 0; i < count; i++){
        if (elements[i] == item) return i;
    }
    return -1;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    int index = getItem(item);
    if (index == -1) return;
    elements[index] = elements[count - 1];
    count--;
    reheapDown(index);
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    count = 0;
}