#include "merkleTree.h"
#include "testMerkleTree.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    run_tests();

    std::vector<std::string> transactions = {
        "Tx1", "Tx2", "Tx3", "Tx4", "Tx5"};

    // Random Tx numbers.
    for (size_t i = 0; i < transactions.size(); ++i)
    {
        transactions[i] += std::to_string(rand());
    }

    MerkleTree merkleTree(transactions);

    std::string input;
    std::cout << "Enter a transaction to check if it's in the Merkle Tree, 'show' to display the tree, or 'q' to quit: ";
    while (std::getline(std::cin, input) && input != "q")
    {
        if (input == "show")
        {
            merkleTree.display();
        }
        else if (merkleTree.contains(input))
        {
            std::cout << "The transaction is in the Merkle Tree." << std::endl;
        }
        else
        {
            std::cout << "The transaction is not in the Merkle Tree." << std::endl;
        }
        std::cout << "Enter another transaction, 'show' to display the tree, or 'q' to quit: ";
    }

    return 0;
}
