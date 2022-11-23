#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    //Helping functions go here
    static void swap(T *a, T *b)
    {
        T temp = *a;
        *a = *b;
        *b = temp;
    }
    static void heapify(T *arr, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && arr[l] > arr[largest])
            largest = l;
        if (r < n && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(&arr[i], &arr[largest]);
            heapify(arr, n, largest);
        }
    }

    static void heapSort(T* start, T* end){
        //TODO
        int n = end - start;
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(start, n, i);
        for (int i = n - 1; i >= 0; i--)
        {
            swap(&start[0], &start[i]);
            heapify(start, i, 0);
        }

        Sorting<T>::printArray(start,end);
    }
};

#endif /* SORTING_H */