#pragma once

#include "../node.h"

class Stack
{
public:
    void push();
    void pop();
    void top();
    void size();
    void isEmpty();

private:
    Node lastElement;
};
