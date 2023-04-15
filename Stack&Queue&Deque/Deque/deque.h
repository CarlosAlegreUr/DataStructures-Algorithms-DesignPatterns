#pragma once

#include "../node.h"

class Deque
{
public:
    Deque() : firstElement(nullptr), lastElement(nullptr), currentSize(0){};

    void pushFront(int _data);
    void pushBack(int _data);
    void popFront();
    void popBack();
    Node &front() const;
    Node &back() const;
    bool isEmpty() const;
    int size() const;

private:
    Node *firstElement;
    Node *lastElement;
    int currentSize;
};
