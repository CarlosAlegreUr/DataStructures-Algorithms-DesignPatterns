#include "merkleTree.h"
#include <iostream>
#include <string>
#include <vector>

void run_tests();

int main()
{
    run_tests();

    std::vector<std::string> transactions = {
        "Tx1", "Tx2", "Tx3", "Tx4", "Tx5"};

    // for (size_t i = 0; i < transactions.size(); ++i)
    // {
    //     transactions[i] += std::to_string(rand());
    // }

    MerkleTree merkleTree(transactions);

    std::string input;
    std::cout << "Enter a transaction to check if it's in the Merkle Tree (type 'q' to quit): ";
    while (std::getline(std::cin, input) && input != "q")
    {
        if (merkleTree.contains(input))
        {
            std::cout << "The transaction is in the Merkle Tree." << std::endl;
        }
        else
        {
            std::cout << "The transaction is not in the Merkle Tree." << std::endl;
        }
        std::cout << "Enter another transaction (type 'q' to quit): ";
    }

    return 0;
}
