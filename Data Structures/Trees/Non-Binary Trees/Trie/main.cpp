#include "trie.h"
#include "testTrie.h"
#include <iostream>

int main() {
    TestTrie::runTest();

    Trie trie;
    std::string operation, word;

    while (true) {
        std::cout << "Enter operation (i for insert, r for remove, s for search, p for prefix search, q to quit): ";
        std::cin >> operation;

        if (operation == "q") {
            break;
        }

        std::cout << "Enter word: ";
        std::cin >> word;

        if (operation == "i") {
            trie.insert(word);
        } else if (operation == "r") {
            trie.remove(word);
        } else if (operation == "s") {
            std::cout << (trie.search(word) ? "Word found" : "Word not found") << std::endl;
        } else if (operation == "p") {
            std::cout << (trie.startsWith(word) ? "Prefix found" : "Prefix not found") << std::endl;
        } else {
            std::cout << "Unknown operation" << std::endl;
        }
    }

    return 0;
}
