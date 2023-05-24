#pragma once

#include <vector>
#include <list>

class Graph
{
public:
    Graph(int V) : V(V)
    {
        adj = new std::list<int>[V];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    std::list<int> getAdj(int v) const
    {
        return adj[v];
    }

    int getV() const
    {
        return V;
    }

private:
    int V;               // No. of vertices
    std::list<int> *adj; // Pointer to an array containing adjacency lists
};
