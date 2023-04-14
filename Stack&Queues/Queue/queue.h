#pragma once

#include "../node.h"

class Queue
{
public:
    Queue() : firstElement(nullptr), lastElement(nullptr), currentSize(0){};

    void enqueue(int _data);
    void dequeue();
    Node &front() const;
    int size() const;
    bool isEmpty() const;

private:
    Node *firstElement;
    Node *lastElement;
    int currentSize;
};
