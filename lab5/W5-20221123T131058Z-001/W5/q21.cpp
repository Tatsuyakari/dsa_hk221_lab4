//iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std
#include <iostream>
#include <string>
#include <cstring>
#include <climits>
#include <utility>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <functional>
#include <algorithm>

using namespace std;

int pairMatching(vector<int>& nums, int target) {
    int count = 0;
    int n = nums.size();
    vector<bool> check(n, false);
    vector<pair<int, int>> idx;
    for (int i = 0; i < n; i++) {
        idx.push_back(make_pair(nums[i], i));
    }
    vector<pair<pair<int, int>, pair<int, int>>> pairs;
    // distinct pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            pairs.push_back(make_pair(idx[i], idx[j]));
        }
    }
    // count pairs with sum = target
    for (size_t i = 0; i < pairs.size(); i++) {
        if (pairs[i].first.first + pairs[i].second.first == target && !check[pairs[i].first.second] && !check[pairs[i].second.second]) {
            count++;
        }
    }

    return count;
}