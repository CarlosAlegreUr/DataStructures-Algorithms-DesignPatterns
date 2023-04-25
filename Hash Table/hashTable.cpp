#include "hashTable.h"

template <typename K, typename V>
HashTable<K, V>::HashTable() {
    // Constructor
}

template <typename K, typename V>
HashTable<K, V>::~HashTable() {
    // Destructor
}

template <typename K, typename V>
void HashTable<K, V>::insert(const K& key, const V& value) {
    // TODO: Implement insert
}

template <typename K, typename V>
V HashTable<K, V>::get(const K& key) const {
    // TODO: Implement get
}

template <typename K, typename V>
void HashTable<K, V>::remove(const K& key) {
    // TODO: Implement remove
}

template <typename K, typename V>
int HashTable<K, V>::size() const {
    // TODO: Implement size
}

template <typename K, typename V>
void HashTable<K, V>::clear() {
    // TODO: Implement clear
}

template <typename K, typename V>
void HashTable<K, V>::resize(int newSize) {
    // TODO: Implement resize
}

template <typename K, typename V>
bool HashTable<K, V>::containsKey(const K& key) const {
    // TODO: Implement containsKey
}

template <typename K, typename V>
bool HashTable<K, V>::containsValue(const V& value) const {
    // TODO: Implement containsValue
}

template <typename K, typename V>
int HashTable<K, V>::hashFunction(const K& key) const {
    // TODO: Implement hashFunction
}

template <typename K, typename V>
int HashTable<K, V>::doubleHashFunction(const K& key) const {
    // TODO: Implement doubleHashFunction
}
