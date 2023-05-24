#pragma once

#include <vector>
#include <list>

class Graph
{
public:
    Graph(int V) : V(V)
    {
        adj = new std::list<std::pair<int, int>>[V];
    }

    ~Graph()
    {
        delete[] adj;
    }

    void addEdge(int v, int w, int weight)
    {
        adj[v].push_back(std::make_pair(w, weight));
    }

    std::list<std::pair<int, int>> getAdj(int v) const
    {
        return adj[v];
    }

    int getV() const
    {
        return V;
    }

private:
    int V;                               // No. of vertices
    std::list<std::pair<int, int>> *adj; // Pointer to an array containing adjacency lists
};
