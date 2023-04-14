#include <iostream>
#include <cassert>
#include "stack.h"
#include "testStack.h"

void testPushPopTop()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    assert(stack.top().data == 3);
    stack.pop();
    assert(stack.top().data == 2);
    stack.pop();
    assert(stack.top().data == 1);
    stack.pop();
    assert(stack.isEmpty());
}

void testSize()
{
    Stack stack;
    assert(stack.size() == 0);
    stack.push(1);
    assert(stack.size() == 1);
    stack.push(2);
    assert(stack.size() == 2);
    stack.push(3);
    assert(stack.size() == 3);
}

void testIsEmpty()
{
    Stack stack;
    assert(stack.isEmpty());
    stack.push(1);
    assert(!stack.isEmpty());
    stack.pop();
    assert(stack.isEmpty());
}
