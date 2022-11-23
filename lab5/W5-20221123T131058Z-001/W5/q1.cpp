#include <iostream>
#include <list>
using namespace std;

// Adjacency is a structure to store list of number
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

class Graph {
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

    // Implement Depth-first search
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        list<int> queue;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        visited[v] = true;
        queue.push_back(v);

        Adjacency *BFS = new Adjacency(V);

        while (!queue.empty())
        {
            v = queue.front();
            queue.pop_front();
            BFS->push(v);
            for (int i = 0; i < adj[v].getSize(); i++)
            {
                int w = adj[v].getElement(i);
                if (!visited[w])
                {
                    visited[w] = true;
                    queue.push_back(w);
                }
            }
        }
        return BFS;
    }

    // Implement Depth-first search
    Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        list<int> stack;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;
        stack.push_front(v);
        Adjacency *DFS = new Adjacency(V);

        while (!stack.empty()) {
            v = stack.front();
            stack.pop_front();
            if (!visited[v]) {
                visited[v] = true;
                DFS->push(v);
                for (int i = 0; i < adj[v].getSize(); i++) {
                    int w = adj[v].getElement(i);
                    if (!visited[w]) {
                        stack.push_front(w);
                    }
                }
            }
        }
        return DFS;
    }
};