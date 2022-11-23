#include<iostream>
#include <list>
using namespace std;

class DirectedGraph
{
    int V;
    list<int> *adj;
    bool isCyclicUtil(int v, bool visited[], bool *rs) {
        if(visited[v] == false) {
            visited[v] = true;
            rs[v] = true;
            list<int>::iterator i;
            for(i = adj[v].begin(); i != adj[v].end(); ++i) {
                if ( !visited[*i] && isCyclicUtil(*i, visited, rs) )
                    return true;
                else if (rs[*i])
                    return true;
            }
        }
        rs[v] = false;
        return false;
    }
public:
    DirectedGraph(){
        V = 0;
        adj = NULL;
    }
    DirectedGraph(int V)
    {
        this->V = V;
        adj = new list<int>[V];
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }
    bool isCyclic() {
        bool *visited = new bool[V];
        bool *recStack = new bool[V];
        for(int i = 0; i < V; i++)
        {
            visited[i] = false;
            recStack[i] = false;
        }
        for(int i = 0; i < V; i++)
            if (isCyclicUtil(i, visited, recStack))
                return true;
        return false;
    }
};