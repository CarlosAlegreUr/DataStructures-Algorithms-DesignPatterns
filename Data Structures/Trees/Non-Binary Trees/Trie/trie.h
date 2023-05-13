#include <string>
#include <vector>

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    std::vector<TrieNode *> children;
    bool isEndOfWord;

    TrieNode(bool endOfWord) : children(std::vector<TrieNode *>(ALPHABET_SIZE, nullptr)), isEndOfWord(endOfWord){};
};

class Trie
{
public:
    // Constructor
    Trie() : root(new TrieNode(false)){};
    ~Trie();

    // Method to insert a new word into the Trie
    void insert(std::string word);

    // Method to remove a word from the Trie
    void remove(std::string word);

    // Method to check if the word is in the Trie
    bool search(std::string word);

    // Method to check if there is any word in the Trie
    // that starts with the given prefix
    bool startsWith(std::string prefix);

private:
    int charToIndex(char c);
    TrieNode *root;
};
