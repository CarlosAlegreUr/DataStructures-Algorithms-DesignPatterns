#include "set.h"
#include <algorithm>

Set::Set() {}

Set::~Set() {}

bool Set::insert(int val)
{
    if (this->hash_map[val] == false)
    {
        this->keys.push_back(val);
        this->hash_map[val] = true;
        return true;
    }
    return false;
}

bool Set::remove(int val)
{
    if (this->hash_map[val] == true)
    {
        std::vector<int>::const_iterator index = std::find(this->keys.begin(), this->keys.end(), val);
        this->keys.erase(index);
        this->hash_map[val] = false;
        return true;
    }
    return false;
}

bool Set::contains(int val)
{
    return this->hash_map[val];
}

std::size_t Set::size() const
{
    return this->keys.size();
}
