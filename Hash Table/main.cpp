#include "hashTable.h"
#include "testHashTable.h"
#include <iostream>
#include <string>
#include <limits>

int main()
{
    HashTable<int> ht;
    char choice;
    std::string key;
    int value;

    do
    {
        std::cout << "\nMenu:\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Get\n";
        std::cout << "3. Remove\n";
        std::cout << "4. Size\n";
        std::cout << "5. Clear\n";
        std::cout << "6. Resize\n";
        std::cout << "7. Contains Key\n";
        std::cout << "8. Contains Value\n";
        std::cout << "9. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case '1':
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << "Enter value: ";
            std::cin >> value;
            ht.insert(key, value);
            break;
        case '2':
            std::cout << "Enter key: ";
            std::cin >> key;
            try
            {
                std::cout << "Value: " << ht.get(key) << std::endl;
            }
            catch (const std::out_of_range &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
            break;
        case '3':
            std::cout << "Enter key: ";
            std::cin >> key;
            ht.remove(key);
            break;
        case '4':
            std::cout << "Size: " << ht.size() << std::endl;
            break;
        case '5':
            ht.clear();
            std::cout << "Cleared hash table." << std::endl;
            break;
        case '6':
            std::cout << "Enter new size: ";
            std::cin >> value;
            ht.resize(value);
            break;
        case '7':
            std::cout << "Enter key: ";
            std::cin >> key;
            std::cout << (ht.containsKey(key) ? "Key exists." : "Key not found.") << std::endl;
            break;
        case '8':
            std::cout << "Enter value: ";
            std::cin >> value;
            std::cout << (ht.containsValue(value) ? "Value exists." : "Value not found.") << std::endl;
            break;
        case '9':
            std::cout << "Quitting...\n";
            break;
        default:
            std::cout << "Invalid option.\n";
        }
    } while (choice != '9');

    return 0;
}
