#include <iostream>
using namespace std;
int foldShift(long long key, int addressSize);
int rotation(long long key, int addressSize);
// Implement function
/*to hashing key using Fold shift or Rotation algorithm.*/

int foldShift(long long key, int addressSize)
{
    int sum = 0;
    int count = 0;
    while (key != 0)
    {
        sum += key % 10;
        key /= 10;
        count++;
        if (count == 3)
        {
            key += sum;
            sum = 0;
            count = 0;
        }
    }
    return sum % (1 << addressSize);
}
int rotation(long long key, int addressSize)
{
    int sum = 0;
    int count = 0;
    while (key != 0)
    {
        sum += key % 10;
        key /= 10;
        count++;
        if (count == 3)
        {
            key = (key << 3) + sum;
            sum = 0;
            count = 0;
        }
    }
    return sum % (1 << addressSize);
}


int main()
{
cout << rotation(600101, 2);
}
