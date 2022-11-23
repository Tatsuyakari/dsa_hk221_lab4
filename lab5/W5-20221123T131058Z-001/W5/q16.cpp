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
                break;
            }
        }
    }
    return found;


}