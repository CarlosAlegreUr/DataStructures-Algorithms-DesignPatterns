#include <stdexcept>
#include "stack.h"

void Stack::push(int _data)
{
    Node *newNode = new Node();
    newNode->data = _data;

    if (!this->isEmpty())
    {
        this->lastElement->nextElement = newNode;
        newNode->prevElement = this->lastElement;
    }
    else
        newNode->prevElement = nullptr;

    newNode->nextElement = nullptr;
    this->lastElement = newNode;
    this->currentSize++;
}

void Stack::pop()
{
    if (this->isEmpty())
        return;
    if (this->size() != 0)
    {
        Node *temp = this->lastElement;
        this->lastElement = this->lastElement->prevElement;
        if (this->lastElement)
        {
            this->lastElement->nextElement = nullptr;
        }
        delete temp;
        this->currentSize--;
    }
}

Node &Stack::top() const
{
    if (!this->isEmpty())
        return *(this->lastElement);
    else
        throw std::runtime_error("Trying to access top of an empty stack.");
}

int Stack::size() const
{
    return currentSize;
}

bool Stack::isEmpty() const
{
    return (currentSize == 0);
}
