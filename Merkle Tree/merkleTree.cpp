#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
#include <openssl/sha.h>
#include <iomanip>
#include <sstream>

std::string sha256(const std::string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data.c_str(), data.size());
    SHA256_Final(hash, &sha256);
    std::stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class MerkleTree {
public:
    MerkleTree(const std::vector<std::string>& transactions) {
        buildTree(transactions);
    }

    bool contains(const std::string& transaction) {
        std::string hash = sha256(transaction);
        return std::find(hashes.begin(), hashes.end(), hash) != hashes.end();
    }

private:
    std::vector<std::string> hashes;

    void buildTree(const std::vector<std::string>& transactions) {
        if (transactions.empty()) return;

        std::vector<std::string> currentLevel;

        for (const auto& tx : transactions) {
            currentLevel.push_back(sha256(tx));
        }

        while (currentLevel.size() > 1) {
            std::vector<std::string> nextLevel;

            for (size_t i = 0; i < currentLevel.size(); i += 2) {
                if (i + 1 < currentLevel.size()) {
                    nextLevel.push_back(sha256(currentLevel[i] + currentLevel[i + 1]));
                } else {
                    nextLevel.push_back(currentLevel[i]);
                }
            }

            hashes.insert(hashes.end(), currentLevel.begin(), currentLevel.end());
            currentLevel = nextLevel;
        }

        hashes.push_back(currentLevel[0]);
    }
};

int main() {
    std::vector<std::string> transactions = {
        "Tx1", "Tx2", "Tx3", "Tx4", "Tx5"
    };

    for (int i = 0; i < transactions.size(); ++i) {
        transactions[i] += std::to_string(rand());
    }

    MerkleTree merkleTree(transactions);

    std::string input;
    std::cout << "Enter a transaction to check if it's in the Merkle Tree (type 'exit' to quit): ";
    while (std::getline(std::cin, input) && input != "exit") {
        if (merkleTree.contains(input)) {
            std::cout << "The transaction is in the Merkle Tree." << std::endl;
        } else {
            std::cout << "The transaction is not in the Merkle Tree." << std::endl;
        }
        std::cout << "Enter another transaction (type 'exit' to quit): ";
    }

    return 0;
}
