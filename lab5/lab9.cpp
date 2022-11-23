#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

template<T>
class Heap{
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
        delete []elements;
    }
    void push(T item);
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]";
    }
    
private:
    void ensureCapacity(int minCapacity); 
    void reheapUp(int position);
};

// Your code here
template<class T>
void Heap<T>::push(T item){
   ensureCapacity(count+1);
    elements[count] = item;
    reheapUp(count);
    count++;

}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if(minCapacity > capacity){
        T *temp = new T[capacity*2];
        for(int i = 0; i < capacity; i++){
            temp[i] = elements[i];
        }
        delete []elements;
        elements = temp;
        capacity *= 2;
    }

}

template<class T>
void Heap<T>::reheapUp(int position){
    int parent = (position-1)/2;
    if(elements[position] > elements[parent]){
        T temp = elements[position];
        elements[position] = elements[parent];
        elements[parent] = temp;
        reheapUp(parent);
    }

}