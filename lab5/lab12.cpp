#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
#include <queue>
using namespace std;
template <class T>
class Sorting
{
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

    // Helping functions go here
    static void heapSort(T *start, T *end)
    {
        // TODO
        priority_queue<T> pq;
        //ascending order
        for (int i = 0; i < end - start; i++)
        {
            pq.push(start[i]);
        }
        for (int i = 0; i < end - start; i++)
        {
            start[i] = pq.top();
            pq.pop();
        }
        //reverse order
         for (int i = 0; i < end - start; i++)
        {
            pq.push(start[i]); //pushing elements into the priority queue
        }
        for (int i = end - start - 1; i >= 0; i--)
        {
            start[i] = pq.top(); //replacing the elements in the array with the elements in the priority queue
            pq.pop();
        }
        
    }
};
#endif /* SORTING_H */
// Helping functions go here
static void heapSort(T *start, T *end)
{
    // TODO


    Sorting<T>::printArray(start, end);
}
{
    int arr[4] = {-1, 0, 2, 3};
    Sorting<int>::heapSort(&arr[0], &arr[4]);
}