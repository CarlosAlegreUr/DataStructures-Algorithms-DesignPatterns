#pragma once
#include <vector>
#include <unordered_map>

class Set {
    std::vector<int> keys;
    std::unordered_map<int, bool> hash_map;

public:
    Set();
    ~Set();

    bool insert(int val);
    bool remove(int val);
    bool contains(int val);
    std::size_t size() const;
};
