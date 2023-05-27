#include "testTrie.h"
#include <iostream>

void TestTrie::runTest() {
    Trie trie;

    // insert some words
    trie.insert("hello");
    trie.insert("world");
    trie.insert("hi");

    // test search
    assert(trie.search("hello") == true);
    assert(trie.search("world") == true);
    assert(trie.search("hi") == true);
    assert(trie.search("bye") == false);

    // test prefix search
    assert(trie.startsWith("he") == true);
    assert(trie.startsWith("worl") == true);
    assert(trie.startsWith("h") == true);
    assert(trie.startsWith("by") == false);

    // remove a word
    trie.remove("world");
    assert(trie.search("world") == false);

    std::cout << "All test cases passed" << std::endl;
}
