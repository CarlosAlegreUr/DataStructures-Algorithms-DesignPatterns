#include <iostream>
#include "disjointSet.h"
#include "testDisjointSet.h"

int main() {
    std::cout << "Running tests...\n";
    runTests();
    
    DisjointSet ds(10); // let's assume we have 10 elements initially

    while (true) {
        std::cout << "\nChoose an option:\n"
                  << "1. Union of two sets\n"
                  << "2. Find representative of a set\n"
                  << "q. Quit\n";
        char option;
        std::cin >> option;

        if (option == 'q') {
            break;
        }

        int x, y;
        switch(option) {
            case '1':
                std::cout << "Enter two elements to perform union: ";
                std::cin >> x >> y;
                ds.unionSets(x, y);
                break;
            case '2':
                std::cout << "Enter an element to find its representative: ";
                std::cin >> x;
                std::cout << "Representative of " << x << " is " << ds.find(x) << "\n";
                break;
            default:
                std::cout << "Invalid option. Please try again.\n";
        }
    }

    return 0;
}
