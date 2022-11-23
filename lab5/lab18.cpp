// C++ program to implement interpolation search
#include <bits/stdc++.h>
using namespace std;

// If x is present in arr[0..n-1], then returns
// index of it, else returns -1.
int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos;
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (left <= right && x >= arr[left] && x <= arr[right])
    {
        // Probing the position with keeping
        // uniform distribution in mind.
        pos = left + (((double)(right - left) /
                       (arr[right] - arr[left])) *
                      (x - arr[left]));
        cout << "We traverse on index: " << pos << endl;
        // Condition of target found
        if (arr[pos] == x)
            return pos;

        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, right, x);

        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, left, pos - 1, x);
    }
    return -1;
}

// Driver Code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, -1, -2, -3, -4, -9, 0, 99, 55};

    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 22;
    int result = interpolationSearch(arr, 0, n - 1, x);
    (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
}

// This code is contributed by Mukul Singh.
