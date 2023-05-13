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
    if (!this->search(word) && this->startsWith(word))
    {
        // The word exists as prefix but not as itself.
        TrieNode *it = this->root;
        for (int i = 0; i < word.size(); i++)
        {
            if (i == word.size() - 1)
            {
                it->isEndOfWord = true;
                return;
            }
            else
            {
                int charIndex = this->charToIndex(word[i]);
                it = it->children[charIndex];
            }
        }
    }

    if (!this->search(word))
    {
        // There is not any word with new word as prefix.
        TrieNode *it = this->root;
        for (int i = 0; i < word.size(); i++)
        {
            int index = this->charToIndex(word[i]);
            TrieNode *newNode = new TrieNode(false);
            newNode->isEndOfWord = (i == word.size() - 1) ? true : false;
            it->children[index] = newNode;
            it = newNode;
        }
    }
}

void Trie::remove(std::string word)
{
    TrieNode *it = this->root;
    for (int i = 0; i < word.size(); i++)
    {
        if (i == word.size() - 1 && it->isEndOfWord == true)
        {
            // Las char of the word, check if it's prefix of bigger words.
            for (int j = 0; j < it->children.size(); j++)
            {
                if (it->children[j] != nullptr)
                {
                    // Is prefix;
                    it->isEndOfWord = false;
                    return;
                }
            }

            // It's not prefix.
            TrieNode *it2 = this->root->children[this->charToIndex(word[0])];
            TrieNode *prevOne;
            for (int j = 1; j < word.size(); j++)
            {
                prevOne = it2;
                int charIndex = this->charToIndex(word[j]);
                it2 = it2->children[charIndex];
                delete prevOne;
            }
        }

        // Keep traversing trie till lats char node.
        int charIndex = this->charToIndex(word[i]);
        if (it->children[charIndex] == nullptr)
            return;
        else
            it = it->children[charIndex];
    }
}

bool Trie::search(std::string word)
{
    TrieNode *it = this->root;
    for (int i = 0; i < word.size(); i++)
    {
        int charIndex = this->charToIndex(word[i]);
        if (it->children[charIndex] == nullptr || (i == word.size() - 1 && it->isEndOfWord == false))
            return false;
        else
            it = it->children[charIndex];
    }
    return true;
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
