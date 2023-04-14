#include "stack.h"

void Stack::push(int _data)
{
    Node *newNode = new Node();
    newNode->data = _data;
    this->lastElement.nextElement = newNode;
    newNode->prevElement = &this->lastElement;
    this->lastElement = *newNode;
}

void Stack::pop()
{
    if (this->size() != 0)
        this->lastElement = *this->lastElement.prevElement;
}

Node &Stack::top()
{
    return this->lastElement;
}

int Stack::size()
{
    if (this->lastElement.data != -1)
    {
        int size = 1;
        Node *iterator = &this->lastElement;
        while (iterator != nullptr)
        {
            size++;
            iterator = iterator->prevElement;
        }
        return size;
    }
    return 0;
}

bool Stack::isEmpty()
{
    return (this->size() == 0);
}
