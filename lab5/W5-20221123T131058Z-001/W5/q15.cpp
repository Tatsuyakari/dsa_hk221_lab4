#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int x)
{
    // to search for value x in array arr using recursion.
    //After traverse an index in array, we print out this index using cout << "We traverse on index: " << index << endl;
    //
    //Note that middle of left and right is floor((right-left)/2)

    if (right >= left) {
        int mid = left + (right - left) / 2;
        cout << "We traverse on index: " << mid << endl;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);
        return binarySearch(arr, mid + 1, right, x);
    }
    return -1;
}