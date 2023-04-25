#pragma once

#include <string>
#include <vector>

template <typename K, typename V>
class HashTable {
public:
    HashTable();
    ~HashTable();

    void insert(const K& key, const V& value);
    V get(const K& key) const;
    void remove(const K& key);
    int size() const;
    void clear();
    void resize(int newSize);
    bool containsKey(const K& key) const;
    bool containsValue(const V& value) const;

private:
    int hashFunction(const K& key) const;
    int doubleHashFunction(const K& key) const;
};
