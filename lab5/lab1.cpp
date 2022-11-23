#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
    list<int> adjList;
    int size;

public:
    Adjacency() {}
    Adjacency(int V) {}
    void push(int data)
    {
        adjList.push_back(data);
        size++;
    }
    void print()
    {
        for (auto const &i : adjList)
            cout << " -> " << i;
    }
    void printArray()
    {
        for (auto const &i : adjList)
            cout << i << " ";
    }
    int getSize() { return adjList.size(); }
    int getElement(int idx)
    {
        auto it = adjList.begin();
        advance(it, idx);
        return *it;
    }
};
class Graph
{
private:
    int V;
    Adjacency *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new Adjacency[V];
    }

    void addEdge(int v, int w)
    {
        adj[v].push(w);
        adj[w].push(v);
    }

    void printGraph()
    {
        for (int v = 0; v < V; ++v)
        {
            cout << "\nAdjacency list of vertex " << v << "\nhead ";
            adj[v].print();
        }
    }

    Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        // TODO
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        list<int> queue;
        visited[v] = true;
        queue.push_back(v);
        Adjacency *result = new Adjacency(V);
        while (!queue.empty())
        {
            v = queue.front();
            result->push(v);
            queue.pop_front();
            for (int i = 0; i < adj[v].getSize(); i++)
            {
                if (!visited[adj[v].getElement(i)])
                {
                    visited[adj[v].getElement(i)] = true;
                    queue.push_back(adj[v].getElement(i));
                }
            }
        }
        return result;
    }
    Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        // TODO
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        list<int> stack;
        visited[v] = true;
        stack.push_front(v);
        Adjacency *result = new Adjacency(V);
        while (!stack.empty())
        {
            v = stack.front();
            result->push(v);
            stack.pop_front();
            for (int i = 0; i < adj[v].getSize(); i++)
            {
                if (!visited[adj[v].getElement(i)])
                {
                    visited[adj[v].getElement(i)] = true;
                    stack.push_front(adj[v].getElement(i));
                }
            }
        }
        return result;
    }
};
int main()
{
    int V = 6;
    int visited = 0;

    Graph g(V);
    Adjacency *arr = new Adjacency(V);
    int edge[][2] = {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 4}, {3, 4}, {3, 5}, {4, 5}};

    for (int i = 0; i < 8; i++)
    {
        g.addEdge(edge[i][0], edge[i][1]);
    }

    arr = g.BFS(visited);
    arr->printArray();
    delete arr;
    int V = 8, visited = 0;

    Graph g(V);
    Adjacency *arr;
    int edge[][2] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {2, 5}, {2, 6}, {4, 6}, {6, 7}};
    for (int i = 0; i < 9; i++)
    {
        g.addEdge(edge[i][0], edge[i][1]);
    }

    // g.printGraph();
    // cout << endl;
    arr = g.DFS(visited);
    arr->printArray();
    delete arr;
}