#pragma once

#include <string>
#include <vector>

#include <iostream>
#include <string>
#include <limits>

template <typename V>
class HashTable
{
public:
    HashTable() : currentSize(0), data(10) {}
    ~HashTable();

    void insert(const std::string &key, const V &value);
    V get(const std::string &key) const;
    void remove(const std::string &key);
    int size() const;
    void clear();
    void resize(int newSize);
    bool containsKey(const std::string &key) const;
    bool containsValue(const V &value) const;

private:
    int hashFunction(const std::string &key) const;
    int doubleHashFunction(int oldIndex) const;
    int getIndexOf(const std::string &key) const;

    std::vector<std::pair<std::string, V>> data;
    std::vector<std::string> keys;
    int currentSize;
};

template <typename V>
HashTable<V>::~HashTable() {}

template <typename V>
void HashTable<V>::insert(const std::string &key, const V &value)
{
    if (this->size() / this->data.size() > 0.5)
        this->resize(2 * this->size());

    int index = this->hashFunction(key);
    if (this->data[index].first == "")
    {
        this->data[index].second = value;
        this->keys.push_back(key);
        this->currentSize++;
    }
    else
    {
        do
        {
            index = this->doubleHashFunction(index);
        } while (this->data[index].first == "");

        this->data[index].second = value;
        this->keys.push_back(key);
        this->currentSize++;
    }
}

template <typename V>
V HashTable<V>::get(const std::string &key) const
{
    int index = getIndexOf(key);
    if (index != -1)
        return this->data[index].second;
    else
        throw std::out_of_range("Key not found in hash table");
}

template <typename V>
void HashTable<V>::remove(const std::string &key)
{
    if (this->size() > 0)
    {
        int index = getIndexOf(key);
        this->data[index].first = "";
        currentSize--;

        for (int i = 0; i < this->keys.size(); i++)
        {
            if (this->keys[i] == key)
                this->keys.erase(this->keys.begin() + i);
        }
    }
}

template <typename V>
int HashTable<V>::size() const
{
    return this->currentSize;
}

template <typename V>
void HashTable<V>::clear()
{
    this->data.clear();
    this->keys.clear();
    this->data.resize(10);
    this->currentSize = 0;
}

template <typename V>
void HashTable<V>::resize(int newSize)
{
    std::vector<std::pair<std::string, V>> oldData = this->data;
    this->data.clear();
    this->data.resize(newSize);
    this->currentSize = 0;
    for (int i = 0; i < oldData.size(); i++)
    {
        if (oldData[i].first != "")
            this->insert(oldData[i].first, oldData[i].second);
    }
}

template <typename V>
bool HashTable<V>::containsKey(const std::string &key) const
{
    for (int i = 0; i < this->keys.size(); i++)
    {
        if (this->keys[i] == key)
            return true;
    }
    return false;
}

template <typename V>
bool HashTable<V>::containsValue(const V &value) const
{
    for (int i = 0; i < this->keys.size(); i++)
    {
        if (this->data[getIndexOf(this->keys[i])].second == value)
            return true;
    }
    return false;
}

template <typename V>
int HashTable<V>::hashFunction(const std::string &key) const
{
    std::string ascii;
    for (char c : key)
    {
        ascii += std::to_string(int(c));
    }
    int index = std::stoi(ascii) % this->data.size();
    return index;
}

template <typename V>
int HashTable<V>::doubleHashFunction(int oldIndex) const
{
    int newIndex = (oldIndex + 7700 % hashFunction("randomizer") * 34) % this->data.size();
    return newIndex;
}

// If -1 table needs to be resized.
template <typename V>
int HashTable<V>::getIndexOf(const std::string &key) const
{
    int timesChecked = 0;
    int index = this->hashFunction(key);
    if (this->data[index].first == key)
        return index;
    else
    {
        timesChecked++;
        do
        {
            index = this->doubleHashFunction(index);
        } while (this->data[index].first != key && timesChecked <= this->data.size());

        if (this->data[index].first != key)
            return -1;
        else
            return index;
    }
}
