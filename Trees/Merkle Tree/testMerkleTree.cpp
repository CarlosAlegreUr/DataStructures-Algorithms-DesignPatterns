#include "merkleTree.h"
#include <iostream>
#include <cassert>

void run_tests()
{
    std::vector<std::string> transactions = {"Tx1", "Tx2", "Tx3", "Tx4", "Tx5"};

    MerkleTree merkleTree(transactions);

    for (const auto &tx : transactions)
    {
        assert(merkleTree.contains(tx));
    }

    std::string nonExistentTransaction = "NonExistent";
    assert(!merkleTree.contains(nonExistentTransaction));

    std::cout << "All tests passed." << std::endl;
}
