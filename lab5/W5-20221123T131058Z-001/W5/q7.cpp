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

struct Graph
{
    int V, E;
    vector< pair<int, pair<int, int>> > edges;
    // Constructor
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({ w, {u, v} });
    }

    //YOUR CODE HERE
    //Given an undirected, connected and weighted graph, find Minimum Spanning Tree (MST) of the graph using Kruskal’s algorithm.
    //
    //Below are the steps for finding MST using Kruskal’s algorithm:
    //
    //1. Sort all the edges in non-decreasing order of their weight.
    //
    //2. Pick the smallest edge. Check if it forms a cycle with the spanning tree formed so far. If cycle is not formed, include this edge. Else, discard it.
    //
    //3. Repeat step#2 until there are (V-1) edges in the spanning tree.

    // Some helping functions
    int find(vector<int>& parent, int i)
    {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    void Union(vector<int>& parent, int x, int y)
    {
        int xset = find(parent, x);
        int yset = find(parent, y);
        if(xset != yset)
            parent[xset] = yset;
    }


    int kruskalMST() {
        // TODO: return weight of the minimum spanning tree.
        int mst_wt = 0;
        vector< pair<int, pair<int, int>> > result;
        vector<int> parent(V, -1);
        sort(edges.begin(), edges.end());
        for(int i = 0; i < E; i++) {
            int u = edges[i].second.first;
            int v = edges[i].second.second;
            int set_u = find(parent, u);
            int set_v = find(parent, v);
            if(set_u != set_v) {
                mst_wt += edges[i].first;
                result.push_back(edges[i]);
                Union(parent, set_u, set_v);
            }
        }
        return mst_wt;
    }
};