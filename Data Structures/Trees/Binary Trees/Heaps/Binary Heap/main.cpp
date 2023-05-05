#include "binaryHeap.h"
#include "testBinaryHeap.h"
#include <iostream>

int main()
{
    runAllTests();

    BinaryHeap bh;
    char choice;
    int value;

    do
    {
        std::cout << "Menu:\n"
                  << "1. Insert\n"
                  << "2. Get Minimum\n"
                  << "3. Delete Minimum\n"
                  << "4. Is Empty\n"
                  << "q. Quit\n"
                  << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case '1':
            std::cout << "Enter a value to insert: ";
            std::cin >> value;
            bh.insert(value);
            break;
        case '2':
            if (!bh.isEmpty())
                std::cout << "Minimum value: " << bh.getMin() << std::endl;
            else
                std::cout << "Heap is empty." << std::endl;
            break;
        case '3':
            bh.deleteMin();
            break;
        case '4':
            std::cout << "Is Empty: " << (bh.isEmpty() ? "Yes" : "No") << std::endl;
            break;
        case 'q':
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 'q');

    return 0;
}
