# Hash Table Implementation using Double Hashing

This project contains a simple C++ implementation of a hash table using double hashing as a collision resolution technique. The project includes a main program for interacting with the hash table as well as some tests to validate functionality.

# WARNING: MAIN.CPP NOT FUNCTIONAL (TODO: Fix one day)
This is probably due to some kind of overflow in the ascii variable in the hashFunction:
template <typename V>
int HashTable<V>::hashFunction(const std::string &key) const
{
    std::string ascii;
    for (char c : key)
    {
        ascii += std::to_string(int(c));
    }
    int index = std::stoi(ascii) % this->data.size();
    return index;
}

Also quit program function not working, click Ctrl+C to leave.

Other options also throw this stoi() prblem...

Regardless all this problems this HashTable implementation gives a solid grasp of what and how HashTable are and work.