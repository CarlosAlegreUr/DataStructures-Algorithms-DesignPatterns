#pragma once

#include <string>
#include <vector>

class MerkleTree
{
public:
    MerkleTree(const std::vector<std::string> &transactions);

    bool contains(const std::string &transaction) const;

private:
    std::vector<std::string> hashes;

    void buildTree(const std::vector<std::string> &transactions);
};
