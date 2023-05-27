# Trie Data Structure in C++

A Trie, also known as a Prefix Tree or Digital Tree, is a tree-based data structure that enables efficient search, insert, and delete operations on strings. It's an ordered tree with the most remarkable property being that prefixes of items are shared: all descendants of a node have a common prefix associated with that node, and the root is associated with an empty string.

This repository contains a basic but fully functional implementation of a Trie in C++. 

## Trie Implementation Details

The Trie structure is designed around the `TrieNode` struct and `Trie` class.

### TrieNode Struct
The `TrieNode` struct represents a single node in the Trie. Each node has two properties:
- `children`: A vector of pointers to the node's child nodes, initialized to nullptr. Each element in the vector represents a letter of the alphabet.
- `isEndOfWord`: A boolean flag to signify the end of a word.

### Trie Class
The `Trie` class encapsulates the Trie structure and provides the following methods for interacting with the Trie:

- `insert(std::string word)`: Inserts a word into the Trie.
- `remove(std::string word)`: Removes a word from the Trie.
- `search(std::string word)`: Checks if a word is in the Trie.
- `startsWith(std::string prefix)`: Checks if there is any word in the Trie that starts with the given prefix.
