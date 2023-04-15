#include <iostream>
#include "deque.h"
#include "testDeque.h"

void runTests();

void displayDeque(Deque &deque)
{
    if (deque.isEmpty())
    {
        std::cout << "The deque is empty." << std::endl;
        return;
    }

    Node *iterator = &deque.front();
    while (iterator != nullptr)
    {
        std::cout << iterator->data;

        if (iterator->nextElement != nullptr)
        {
            std::cout << ", ";
        }

        iterator = iterator->nextElement;
    }
    std::cout << std::endl;
}

int main()
{
    Deque deque;
    char choice;
    int data;
    runTests();

    while (true)
    {
        std::cout << "Options:" << std::endl
                  << "  1. Push Front" << std::endl
                  << "  2. Push Back" << std::endl
                  << "  3. Pop Front" << std::endl
                  << "  4. Pop Back" << std::endl
                  << "  5. Front" << std::endl
                  << "  6. Back" << std::endl
                  << "  7. Size" << std::endl
                  << "  8. Is Empty" << std::endl
                  << "  q. Quit" << std::endl
                  << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 'q')
        {
            break;
        }

        switch (choice)
        {
        case '1':
            std::cout << "Enter data: ";
            std::cin >> data;
            deque.pushFront(data);
            displayDeque(deque);
            break;
        case '2':
            std::cout << "Enter data: ";
            std::cin >> data;
            deque.pushBack(data);
            displayDeque(deque);
            break;
        case '3':
            deque.popFront();
            displayDeque(deque);
            break;
        case '4':
            deque.popBack();
            displayDeque(deque);
            break;
        case '5':
            if (!deque.isEmpty())
            {
                std::cout << "Front: " << deque.front().data << std::endl;
                displayDeque(deque);
            }
            else
            {
                std::cout << "The deque is empty." << std::endl;
            }
            break;
        case '6':
            if (!deque.isEmpty())
            {
                std::cout << "Back: " << deque.back().data << std::endl;
                displayDeque(deque);
            }
            else
            {
                std::cout << "The deque is empty." << std::endl;
            }
            break;
        case '7':
            std::cout << "Size: " << deque.size() << std::endl;
            displayDeque(deque);
            break;
        case '8':
            std::cout << "Empty: " << (deque.isEmpty() ? "true" : "false") << std::endl;
            displayDeque(deque);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
        std::cout << std::endl;
    }

    return 0;
}

void runTests()
{
    testPushFrontBack();
    testPopFrontBack();
    testFrontBack();
    testSizeIsEmpty();

    std::cout << "All tests passed!" << std::endl
              << std::endl;
}
