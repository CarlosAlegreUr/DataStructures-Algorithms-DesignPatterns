#pragma once
#include <vector>

class DisjointSet
{
    std::vector<int> parent;
    std::vector<int> rank;
    std::vector<int> value; // Additional vector to store values

public:
    DisjointSet(int n);

    int find(int x);
    void unionSets(int x, int y);
    int getValue(int x);           // Get the value of a node
    void setValue(int x, int val); // Set the value of a node
};
