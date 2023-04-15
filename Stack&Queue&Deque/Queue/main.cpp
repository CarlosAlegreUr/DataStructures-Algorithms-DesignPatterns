#include <iostream>
#include "queue.h"
#include "testQueue.h"

void runTests();
void displayQueue(Queue &queue);

int main()
{
    Queue queue;
    char choice;
    int data;
    runTests();

    while (true)
    {
        std::cout << "Options:" << std::endl
                  << "  1. Enqueue" << std::endl
                  << "  2. Dequeue" << std::endl
                  << "  3. Front" << std::endl
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
            queue.enqueue(data);
            displayQueue(queue);
            break;
        case '2':
            queue.dequeue();
            displayQueue(queue);
            break;
        case '3':
            if (!queue.isEmpty())
            {
                std::cout << "Front: " << queue.front().data << std::endl;
                displayQueue(queue);
            }
            else
            {
                std::cout << "The queue is empty." << std::endl;
            }
            break;
        case '4':
            std::cout << "Size: " << queue.size() << std::endl;
            displayQueue(queue);
            break;
        case '5':
            std::cout << "Empty: " << (queue.isEmpty() ? "true" : "false") << std::endl;
            displayQueue(queue);
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
    testEnqueueDequeueFront();
    testSize();
    testIsEmpty();

    std::cout << "All tests passed!" << std::endl
              << std::endl;
}

void displayQueue(Queue &queue)
{
    if (queue.isEmpty())
    {
        std::cout << "The queue is empty." << std::endl;
        return;
    }

    Node *iterator = &queue.front();
    while (iterator != nullptr)
    {
        std::cout << iterator->data;
        if (iterator->nextElement != nullptr)
        {
            std::cout << ",";
        }
        iterator = iterator->nextElement;
    }
    std::cout << std::endl;
}
