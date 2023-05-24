#include <iostream>
#include "set.h"
#include "testSet.h"

void interactWithUser() {
    Set set;
    char option = ' ';
    int val = 0;

    while (true) {
        std::cout << "Please choose an option (i = insert, r = remove, c = contains, s = size, q = quit): ";
        std::cin >> option;
        switch (option) {
            case 'i':
                std::cout << "Enter a value to insert: ";
                std::cin >> val;
                set.insert(val);
                break;
            case 'r':
                std::cout << "Enter a value to remove: ";
                std::cin >> val;
                set.remove(val);
                break;
            case 'c':
                std::cout << "Enter a value to check: ";
                std::cin >> val;
                if (set.contains(val))
                    std::cout << "The set contains " << val << ".\n";
                else
                    std::cout << "The set does not contain " << val << ".\n";
                break;
            case 's':
                std::cout << "The set contains " << set.size() << " elements.\n";
                break;
            case 'q':
                return;
            default:
                std::cout << "Unknown option: " << option << '\n';
        }
    }
}

int main() {
    run_tests();
    interactWithUser();
    return 0;
}
