#pragma once

#include "../node.h"

class Stack
{
public:
    void push(int _data);
    void pop();
    Node top();
    int size();
    bool isEmpty();

private:
    Node lastElement;
};
