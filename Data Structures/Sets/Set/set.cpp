#include "set.h"
#include <algorithm>

Set::Set() {}

Set::~Set() {}

bool Set::insert(int val)
{
    if (this->hash_map.count(val) == 0)
    {
        this->keys.push_back(val);
        this->hash_map[val] = true;
        return true;
    }
    return false;
}

bool Set::remove(int val)
{
    if (this->hash_map.count(val) > 0)
    {
        auto it = std::find(this->keys.begin(), this->keys.end(), val);
        if (it != this->keys.end())
        {
            std::swap(*it, this->keys.back());
            this->keys.pop_back();
            this->hash_map.erase(val);
            return true;
        }
    }
    return false;
}

bool Set::contains(int val)
{
    return this->hash_map.count(val) > 0;
}

std::size_t Set::size() const
{
    return this->keys.size();
}
