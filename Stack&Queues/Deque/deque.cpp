#include "deque.h"

void Deque::pushFront(int _data) {}

void Deque::pushBack(int _data) {}

void Deque::popFront() {}

void Deque::popBack() {}

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
