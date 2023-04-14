#include <iostream>
#include "stack.h"
#include "testStack.h"

void runTests();

void displayStack(Stack &stack)
{
    Node *iterator = &stack.top();
    while (iterator != nullptr)
    {
        if (iterator->prevElement == nullptr)
        {
            std::cout << iterator->data << " <--" << std::endl;
        }
        else
        {
            std::cout << iterator->data << std::endl;
        }
        iterator = iterator->prevElement;
    }
}

int main()
{
    Stack stack;
    char choice;
    int data;
    runTests();

    while (true)
    {
        std::cout << "Options:" << std::endl
                  << "  1. Push" << std::endl
                  << "  2. Pop" << std::endl
                  << "  3. Top" << std::endl
                  << "  4. Size" << std::endl
                  << "  5. Is Empty" << std::endl
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
            stack.push(data);
            displayStack(stack);
            break;
        case '2':
            stack.pop();
            displayStack(stack);
            break;
        case '3':
            std::cout << "Top: " << stack.top().data << std::endl;
            displayStack(stack);
            break;
        case '4':
            std::cout << "Size: " << stack.size() << std::endl;
            displayStack(stack);
            break;
        case '5':
            std::cout << "Empty: " << (stack.isEmpty() ? "true" : "false") << std::endl;
            displayStack(stack);
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
            break;
        }
        std::cout << std::endl;
    }

    return 0;
}

void runTests() {
    testPushPopTop();
    testSize();
    testIsEmpty();

    std::cout << "All tests passed!" << std::endl << std::endl;
}

