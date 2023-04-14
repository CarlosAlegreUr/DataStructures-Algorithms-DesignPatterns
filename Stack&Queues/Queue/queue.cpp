#include <stdexcept>
#include "queue.h"

void Queue::enqueue(int _data)
{
    Node *newNode = new Node(_data);

    if (this->isEmpty())
    {
        this->firstElement = newNode;
        this->lastElement = newNode;
    }
    else
    {
        this->lastElement->nextElement = newNode;
        this->lastElement = newNode;
    }

    this->currentSize++;
}

void Queue::dequeue()
{
    if (!this->isEmpty())
    {
        Node *toDeleteFirst = this->firstElement;
        if (this->size() > 1)
        {
            this->firstElement = this->firstElement->nextElement;
            this->firstElement->prevElement = nullptr;
        }
        else
        {
            this->firstElement = nullptr;
            this->lastElement = nullptr;
        }

        delete toDeleteFirst;
        this->currentSize--;
    }
}

Node &Queue::front() const
{
    if (!this->isEmpty())
        return *(this->firstElement);
    else
        throw std::runtime_error("Trying to access front of an empty Queue.");
}

int Queue::size() const
{
    return currentSize;
}

bool Queue::isEmpty() const
{
    return (currentSize == 0);
}
