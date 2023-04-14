#include <cassert>
#include "deque.h"
#include "testDeque.h"

void testPushFrontBack()
{
    Deque deque;

    deque.pushFront(1);
    assert(deque.front().data == 1);
    assert(deque.back().data == 1);

    deque.pushBack(2);
    assert(deque.front().data == 1);
    assert(deque.back().data == 2);

    deque.pushFront(3);
    assert(deque.front().data == 3);
    assert(deque.back().data == 2);
}

void testPopFrontBack()
{
    Deque deque;

    deque.pushFront(1);
    deque.pushBack(2);
    deque.pushFront(3);

    deque.popFront();
    assert(deque.front().data == 1);
    assert(deque.back().data == 2);

    deque.popBack();
    assert(deque.front().data == 1);
    assert(deque.back().data == 1);

    deque.popFront();
    assert(deque.isEmpty());
}

void testFrontBack()
{
    Deque deque;

    deque.pushFront(1);
    deque.pushBack(2);
    deque.pushFront(3);

    assert(deque.front().data == 3);
    assert(deque.back().data == 2);
}

void testSizeIsEmpty()
{
    Deque deque;

    assert(deque.isEmpty());
    assert(deque.size() == 0);

    deque.pushFront(1);
    assert(!deque.isEmpty());
    assert(deque.size() == 1);

    deque.pushBack(2);
    assert(!deque.isEmpty());
    assert(deque.size() == 2);

    deque.popFront();
    assert(!deque.isEmpty());
    assert(deque.size() == 1);

    deque.popBack();
    assert(deque.isEmpty());
    assert(deque.size() == 0);
}
