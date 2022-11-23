#include <iostream>
#include <cmath>
using namespace std;
/*In midSquare function: we eliminate 2 last digits and get the 4 next digits.

In digitExtraction: extractDigits is a sorted array from smallest to largest index of digit in seed (index starts from 0). The array has size size.*/
long int midSquare(long int seed)
{
    long int square = seed * seed;
    long int mid = square / 100;
    return mid % 10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed % mod;
}
long int digitExtraction(long int seed, int *extractDigits, int size)
{
            long int result = 0;
    for (int i = 0; i < size; i++)
    {
        long int temp = seed;
        for (int j = 0; j < extractDigits[i]; j++)
        {
            temp /= 10;
        }
        result += temp % 10;
        result *= 10;
    }
    return result / 10;
}

int main()
{
    int a[] = {1, 2, 5};
    cout << digitExtraction(122443, a, 3)<<endl;
    cout <<midSquare(9452);

}