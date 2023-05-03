#pragma once

#include "../node.h"

class Stack
{
public:
    Stack() : lastElement(nullptr), currentSize(0){};

    void push(int _data);
    void pop();
    Node &top() const;
    int size() const;
    bool isEmpty() const;

private:
    Node *lastElement;
    int currentSize;
};
