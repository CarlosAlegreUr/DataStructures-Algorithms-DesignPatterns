// THIS CODE IS NOT IMPLEMENTED, IT'S JUST SOME EXAMPLE TO SHOW HOW VERYFYING WOULD TAKE PLACE
// THE PATH SHOULD BE GRANTED BY SOMEONE WHO HAS THE WHOLE MERKLE TREE
#pragma once

#include <string>
#include <vector>

class VerifyingClient
{
public:
    static bool verify_path_recursive(const std::vector<std::string> &path, const std::string &transaction, const std::string &expected_hash);
    static bool verify_path_iterative(const std::vector<std::string> &path, const std::string &transaction, const std::string &expected_hash);
};
