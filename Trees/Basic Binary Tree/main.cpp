#include <iostream>
#include "binaryTree.h"
#include "testBinaryTree.h"

int main()
{
    TestBinaryTree::runAllTests();

    BinaryTree tree;
    char option;
    int value;

    do
    {
        std::cout << "\nBinary Tree Menu\n";
        std::cout << "1. Insert\n";
        std::cout << "2. Remove\n";
        std::cout << "3. Search\n";
        std::cout << "4. Height\n";
        std::cout << "5. Size\n";
        std::cout << "6. Is Balanced\n";
        std::cout << "7. Path Sum\n";
        std::cout << "8. Level Order Traversal\n";
        std::cout << "q. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> option;

        switch (option)
        {
        case '1':
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            tree.insert(value);
            break;
        case '2':
            std::cout << "Enter value to remove: ";
            std::cin >> value;
            tree.remove(value);
            break;
        case '3':
            std::cout << "Enter value to search: ";
            std::cin >> value;
            std::cout << (tree.search(value) ? "Found\n" : "Not Found\n");
            break;
        case '4':
            std::cout << "Height: " << tree.height() << "\n";
            break;
        case '5':
            std::cout << "Size: " << tree.size() << "\n";
            break;
        case '6':
            std::cout << "Is Balanced: " << (tree.isBalanced() ? "Yes\n" : "No\n");
            break;
        case '7':
            std::cout << "Enter target sum: ";
            std::cin >> value;
            std::cout << "Number of paths: " << tree.pathSum(value) << "\n";
            break;
        case '8':
            std::cout << "Level Order Traversal: \n";
            tree.levelOrderTraversal();
            break;
        case 'q':
            std::cout << "Exiting...\n";
            break;
        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    } while (option != 'q');

    return 0;
}
