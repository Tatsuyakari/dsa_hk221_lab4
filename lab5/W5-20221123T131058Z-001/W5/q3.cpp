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

void dfs(int node, vector<int> graph[], vector<bool>& visited) {
    if (visited[node]) return;
    visited[node] = true;
    for (size_t i = 0; i < graph[node].size(); i++) {
        dfs(graph[node][i], graph, visited);
    }
}

// Where edges is the adjacency-list representing the graph (this list has between 0 and 1000 lists). This function returns the number of connected components of the graph.
//Define a function dfs(), this will take node, graph, an array called visited,
//
//if visited[node] is false, then −
//
//visited[node] := true
//
//for initialize i := 0, when i < size of graph[node], update (increase i by 1), do −
//
//dfs(graph[node, i], graph, visited)
//
//From the main method do the following −
//
//Define an array visited of size n
//
//if not n is non-zero, then −
//
//Define an array graph[n]
//
//for initialize i := 0, when i < size of edges, update (increase i by 1), do −
//
//u := edges[i, 0]
//
//v := edges[i, 1]
//
//insert v at the end of graph[u]
//
//insert u at the end of graph[v]
//
//ret := 0
//
//for initialize i := 0, when i < n, update (increase i by 1), do −
//
//if not visited[i] is non-zero, then −
//
//dfs(i, graph, visited)
//
//(increase ret by 1)
//
//return ret
int connectedComponents(vector<vector<int>>& edges) {
    // STUDENT ANSWER
    int n = edges.size();
    if (n == 0) return 0;
    vector<int> graph[n];
    for (int i = 0; i < n; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ret = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            ret++;
        }
    }
    return ret;
}

