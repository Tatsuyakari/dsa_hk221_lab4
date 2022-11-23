#include <iostream>
using namespace std;
double sqrt(double x)
{
    double left = 0;
    double right = x;
    double mid = (left + right) / 2;
    while (mid * mid != x)
    {
        if (mid * mid > x)
        {
            right = mid;
        }
        else
        {
            left = mid;
        }
        mid = (left + right) / 2;
    }
    return mid;
}
int jumpSearch(int arr[], int x, int n)
{
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = sqrt(n);
    int prev = 0;
    cout << prev << " ";
    while (arr[min(step, n) - 1] < x)
    {
       
        prev = step;
        step += sqrt(n);
        cout << prev << " ";
        if (prev >= n)
            return -1;
    }
    if (step < x && prev >=n ) cout << step << " ";
    while (arr[prev] < x)
    {
        prev++;
        cout << prev << " ";
        if (prev == min(step, n))
            return -1;
    }
    if (arr[prev] == x)
        return prev;
    return -1;
}
int main()
{
	
int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
int x = 1;
int n = sizeof(arr) / sizeof(arr[0]);
int index = jumpSearch(arr, x, n);

if (index != -1) {
    cout << "\nNumber " << x << " is at index " << index;
}
else {
    cout << "\n" << x << " is not in array!";
}
}