#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>
using namespace std;
/*Given an array of distinct integers, find if there are two pairs (a, b) and (c, d) such that a+b = c+d, and a, b, c and d are distinct elements. If there are multiple answers, you can find any of them.*/
// bool findPairs(int arr[], int n, pair<int, int> &pair1, pair<int, int> &pair2)
// {
//     // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
//     //Find the pair in the array that has the same sum
//     //Store the index of the pair in the map
//     map<int, pair<int, int>> m;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             int sum = arr[i] + arr[j];
//             if (m.find(sum) != m.end())
//             {
//                 pair1.first = m[sum].first;
//                 pair1.second = m[sum].second;
//                 pair2.first = i;
//                 pair2.second = j;
//                 return true;S
//             }
//             else
//             {
//                 m[sum] = make_pair(i, j);
//             }
//         }
//     }
//     return false;
// }
bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
    bool found = false;
    vector<pair<int, int>> pairs;
    // distinct pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pairs.push_back(make_pair(arr[i], arr[j]));
        }
    }
    // sort pairs
    sort(pairs.begin(), pairs.end());
    // find 2 pairs with same sum
    for (size_t i = 0; i < pairs.size() - 1; i++) {
        for (size_t j = i + 1; j < pairs.size(); j++) {
            if (pairs[i].first + pairs[i].second == pairs[j].first + pairs[j].second) {
                pair1 = pairs[i];
                pair2 = pairs[j];
                found = true;
                // print pairs
                cout << "(" << pair1.first << ", " << pair1.second << ") and (" << pair2.first << ", " << pair2.second << ")" << endl;
                
                break;
            }
        }
    }
    return found;
}
//checkAnswer function is used to check your answer. 
bool checkAnswer(int arr[], int n, pair<int, int> &pair1, pair<int, int> &pair2)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == 1)
            {
                count++;
                if (count == 1)
                {
                    pair1.first = arr[i];
                    pair1.second = arr[j];
                }
                else if (count == 2)
                {
                    pair2.first = arr[i];
                    pair2.second = arr[j];
                }
            }
        }
    }
    if (count == 2)
        return true;
    return false;
}
int main()
{
int arr[] = { 3, 4, 7, 1, 2, 9, 8 };
int n = sizeof arr / sizeof arr[0];
pair<int, int> pair1, pair2;
if (findPairs(arr, n, pair1, pair2)) {
    if (checkAnswer(arr, n, pair1, pair2)) {
        printf("Your answer is correct.\n");
    }
    else printf("Your answer is incorrect.\n");
}
else printf("No pair found.\n");
}