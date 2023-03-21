#pragma once

#include <string>
#include <vector>

class MerkleTree
{
public:
    MerkleTree(const std::vector<std::string> &transactions);

    bool contains(const std::string &transaction) const;
    void display() const;

private:
    std::vector<std::string> hashes;
    std::vector<std::string> transactions;

    void buildTree(const std::vector<std::string> &transactions);
};
