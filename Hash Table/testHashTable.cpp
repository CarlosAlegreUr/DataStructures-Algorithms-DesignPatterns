#include "testHashTable.h"
#include "hashTable.h"
#include <iostream>
#include <string>
#include <cassert>

void testInsertAndGet() {
    HashTable<std::string, int> ht;
    ht.insert("one", 1);
    ht.insert("two", 2);
    ht.insert("three", 3);

    assert(ht.get("one") == 1);
    assert(ht.get("two") == 2);
    assert(ht.get("three") == 3);
}

void testRemove() {
    HashTable<std::string, int> ht;
    ht.insert("one", 1);
    ht.insert("two", 2);
    ht.insert("three", 3);

    ht.remove("two");

    assert(!ht.containsKey("two"));
}

void testSize() {
    HashTable<std::string, int> ht;
    ht.insert("one", 1);
    ht.insert("two", 2);
    ht.insert("three", 3);

    assert(ht.size() == 3);
}

void testClear() {
    HashTable<std::string, int> ht;
    ht.insert("one", 1);
    ht.insert("two", 2);
    ht.insert("three", 3);

    ht.clear();

    assert(ht.size() == 0);
}

void testResize() {
    HashTable<std::string, int> ht;
    for (int i = 1; i <= 10; ++i) {
        ht.insert("key" + std::to_string(i), i);
    }

    ht.resize(20);

    assert(ht.size() == 10);
}

void testContainsKey() {
    HashTable<std::string, int> ht;
    ht.insert("one", 1);
    ht.insert("two", 2);
    ht.insert("three", 3);

    assert(ht.containsKey("one"));
    assert(!ht.containsKey("four"));
}

void testContainsValue() {
    HashTable<std::string, int> ht;
    ht.insert("one", 1);
    ht.insert("two", 2);
    ht.insert("three", 3);

    assert(ht.containsValue(1));
    assert(!ht.containsValue(4));
}

void runTests() {
    std::cout << "Running hash table tests..." << std::endl;

    testInsertAndGet();
    testRemove();
    testSize();
    testClear();
    testResize();
    testContainsKey();
    testContainsValue();

    std::cout << "All tests passed." << std::endl;
}
