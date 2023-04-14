#include <cassert>
#include "queue.h"
#include "testQueue.h"

void testEnqueueDequeueFront()
{
    Queue queue;

    queue.enqueue(1);
    assert(queue.front().data == 1);

    queue.enqueue(2);
    assert(queue.front().data == 1);

    queue.dequeue();
    assert(queue.front().data == 2);

    queue.dequeue();
    assert(queue.isEmpty());
}

void testSize()
{
    Queue queue;

    assert(queue.size() == 0);

    queue.enqueue(1);
    assert(queue.size() == 1);

    queue.enqueue(2);
    assert(queue.size() == 2);

    queue.dequeue();
    assert(queue.size() == 1);

    queue.dequeue();
    assert(queue.size() == 0);
}

void testIsEmpty()
{
    Queue queue;

    assert(queue.isEmpty());

    queue.enqueue(1);
    assert(!queue.isEmpty());

    queue.dequeue();
    assert(queue.isEmpty());
}
