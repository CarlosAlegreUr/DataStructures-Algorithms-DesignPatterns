#include "merkleTree.h"
#include <openssl/evp.h>
#include <algorithm>
#include <iomanip>
#include <sstream>

std::string sha256(const std::string &data)
{
    EVP_MD_CTX *mdctx;
    const EVP_MD *md;
    unsigned char hash[EVP_MAX_MD_SIZE];
    unsigned int md_len;

    md = EVP_sha256();
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, data.c_str(), data.size());
    EVP_DigestFinal_ex(mdctx, hash, &md_len);
    EVP_MD_CTX_free(mdctx);

    std::stringstream ss;
    for (unsigned int i = 0; i < md_len; ++i)
    {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

MerkleTree::MerkleTree(const std::vector<std::string> &transactions)
{
    buildTree(transactions);
}

bool MerkleTree::contains(const std::string &transaction) const
{
    std::string hash = sha256(transaction);

    // Calculate the number of leaf nodes (the first level of the tree).
    size_t numLeafNodes = (hashes.size() + 1) / 2;

    // Search only the leaf nodes, which are stored in the first half of the 'hashes' vector.
    return std::find(hashes.begin(), hashes.begin() + numLeafNodes, hash) != hashes.begin() + numLeafNodes;
}

void MerkleTree::buildTree(const std::vector<std::string> &transactions)
{
    if (transactions.empty())
        return;

    std::vector<std::string> currentLevel;

    for (const auto &tx : transactions)
    {
        currentLevel.push_back(sha256(tx));
    }

    while (currentLevel.size() > 1)
    {
        std::vector<std::string> nextLevel;

        for (size_t i = 0; i < currentLevel.size(); i += 2)
        {
            if (i + 1 < currentLevel.size())
            {
                nextLevel.push_back(sha256(currentLevel[i] + currentLevel[i + 1]));
            }
            else
            {
                nextLevel.push_back(currentLevel[i]);
            }
        }

        hashes.insert(hashes.end(), currentLevel.begin(), currentLevel.end());
        currentLevel = nextLevel;
    }

    hashes.push_back(currentLevel[0]);
}
