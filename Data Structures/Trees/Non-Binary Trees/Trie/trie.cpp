#include "trie.h"

int Trie::charToIndex(char c)
{
    return c - 'a';
}

void destroyNodesRec(TrieNode *node)
{
    for (int i = 0; i < node->children.size(); i++)
    {
        if (node->children[i] != nullptr)
            destroyNodesRec(node->children[i]);
    }
    delete node;
}

Trie::~Trie()
{
    destroyNodesRec(this->root);
}

void Trie::insert(std::string word)
{
    TrieNode *it = this->root;
    for (int i = 0; i < word.size(); i++)
    {
        int index = this->charToIndex(word[i]);
        if (it->children[index] == nullptr) // Create new node if it does not exist
        {
            TrieNode *newNode = new TrieNode(i == word.size() - 1);
            it->children[index] = newNode;
            it = newNode;
        }
        else // Traverse to next node
        {
            it = it->children[index];
            if (i == word.size() - 1) // Set isEndOfWord flag to true if it's the end of the word
                it->isEndOfWord = true;
        }
    }
}

bool Trie::removeHelper(TrieNode *node, std::string word, int depth)
{
    if (node == nullptr)
        return false;

    if (depth == word.size())
    {
        if (node->isEndOfWord)
        {
            node->isEndOfWord = false;
            return node->children.empty();
        }
        return false;
    }

    int index = charToIndex(word[depth]);
    if (removeHelper(node->children[index], word, depth + 1))
    {
        delete node->children[index];
        node->children[index] = nullptr;

        return !node->isEndOfWord && node->children.empty();
    }

    return false;
}

void Trie::remove(std::string word)
{
    removeHelper(root, word, 0);
}

bool Trie::search(std::string word)
{
    TrieNode *it = this->root;
    for (int i = 0; i < word.size(); i++)
    {
        int charIndex = this->charToIndex(word[i]);
        if (it->children[charIndex] == nullptr)
            return false;
        else
            it = it->children[charIndex];
    }
    return it->isEndOfWord;
}

bool Trie::startsWith(std::string prefix)
{
    TrieNode *it = this->root;
    for (int i = 0; i < prefix.size(); i++)
    {
        int charIndex = this->charToIndex(prefix[i]);
        if (it->children[charIndex] == nullptr)
            return false;
        else
            it = it->children[charIndex];
    }
    return true;
}

// It doesnt work but dont know why. Maybe figure out one day.
/* void Trie::remove(std::string word)
// {
    // TrieNode *it = this->root;
    // for (int i = 0; i < word.size(); i++)
    // {
        // if (i == word.size() - 1 && it->isEndOfWord == true)
        // {
            // // Last char of the word, check if it's prefix of bigger words.
            // for (int j = 0; j < it->children.size(); j++)
            // {
                // if (it->children[j] != nullptr)
                // {
                    Is prefix;
                    // it->isEndOfWord = false;
                    // return;
                // }
            // }
// 
            It's not prefix.
            // TrieNode *it2 = this->root->children[this->charToIndex(word[0])];
            // TrieNode *prevOne;
            // for (int j = 1; j < word.size(); j++)
            // {
                // prevOne = it2;
                // int charIndex = this->charToIndex(word[j]);
                // it2 = it2->children[charIndex];
// 
                Checks if there are words having as suffix some part of the word being deleted.
                // bool needDeletion = true;
                // for (int k = 0; k < prevOne->children.size(); k++)
                // {
                    // if (prevOne->children[k] != nullptr && k != charIndex)
                    // {
                        // needDeletion = false;
                        // break;
                    // }
                // }
                // if (needDeletion)
                    // delete prevOne;
            // }
        // }
// 
        Keep traversing trie till last char node.
        // int charIndex = this->charToIndex(word[i]);
        // if (it->children[charIndex] == nullptr) // Word is not even in the tire so do nothing.
            // return;
        // else
            // it = it->children[charIndex];
    // }
// }
// */