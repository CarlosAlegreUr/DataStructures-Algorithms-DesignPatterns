#include "deque.h"

void Deque::pushFront(int _data)
{
    Node *newNode = new Node(_data);
    if (this->isEmpty())
    {
        this->firstElement = newNode;
        this->lastElement = newNode;
    }
    else
    {
        newNode->nextElement = this->firstElement;
        this->firstElement->prevElement = newNode;
        this->firstElement = newNode;
    }
    this->currentSize++;
}

void Deque::pushBack(int _data)
{
    Node *newNode = new Node(_data);
    if (this->isEmpty())
    {
        this->firstElement = newNode;
        this->lastElement = newNode;
    }
    else
    {
        newNode->prevElement = this->lastElement;
        this->lastElement->nextElement = newNode;
        this->lastElement = newNode;
    }
    this->currentSize++;
}

void Deque::popFront()
{
    if (!this->isEmpty())
    {
        Node *nodeToDelete = this->firstElement;

        if (this->size() > 1)
        {
            this->firstElement = this->firstElement->nextElement;
            nodeToDelete->nextElement->prevElement = nullptr;
            delete nodeToDelete;
        }
        else
        {
            delete nodeToDelete;
            this->firstElement = nullptr;
            this->lastElement = nullptr;
        }
        this->currentSize--;
    }
}

void Deque::popBack()
{
    if (!this->isEmpty())
    {
        Node *nodeToDelete = this->lastElement;
        if (this->size() > 1)
        {
            this->lastElement = this->lastElement->prevElement;
            nodeToDelete->prevElement->nextElement = nullptr;
            delete nodeToDelete;
        }
        else
        {
            delete nodeToDelete;
            this->firstElement = nullptr;
            this->lastElement = nullptr;
        }
        this->currentSize--;
    }
}

Node &Deque::front() const
{
    return *this->firstElement;
}

Node &Deque::back() const
{
    return *this->lastElement;
}

bool Deque::isEmpty() const
{
    return (this->size() == 0);
}

int Deque::size() const
{
    return this->currentSize;
}
