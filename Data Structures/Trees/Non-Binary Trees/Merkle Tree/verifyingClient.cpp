// THIS CODE IS NOT IMPLEMENTED, IT'S JUST SOME EXAMPLE TO SHOW HOW VERYFYING WOULD TAKE PLACE
// THE PATH SHOULD BE GRANTED BY SOMEONE WHO HAS THE WHOLE MERKLE TREE
#include "verifyingClient.h"
#include "sha256.h"

bool VerifyingClient::verify_path_recursive(const std::vector<std::string> &path, const std::string &transaction, const std::string &expected_hash, size_t index = 0, std::string current_hash = "")
{
    if (index >= path.size())
    {
        return false;
    }

    std::string current_hash = sha256(transaction);

    if (current_hash != path[index])
    {
        return false;
    }

    if (index == 0)
    {
        return current_hash == expected_hash;
    }

    std::string sibling_hash = path[index - 1];
    std::string parent_hash = sha256(current_hash + sibling_hash);

    return verify_path_recursive(path, index - 2, parent_hash, expected_hash);
}

bool VerifyingClient::verify_path_iterative(const std::vector<std::string> &path, const std::string &transaction, const std::string &expected_hash)
{

    std::string current_hash = sha256(transaction);

    if (current_hash != path.back())
    {
        return false;
    }

    for (int i = path.size() - 2; i >= 0; i -= 2)
    {
        std::string sibling_hash = path[i];
        current_hash = sha256(current_hash + sibling_hash);
    }

    return current_hash == expected_hash;
}
