#include "binaryHeap.h"

int BinaryHeap::getParentIndex(int childNodeIndex)
{
    return (childNodeIndex - 1) / 2;
}

int BinaryHeap::getRightChildIndex(int parentIndex)
{
    return 2 * parentIndex + 2;
}

int BinaryHeap::getLeftChildIndex(int parentIndex)
{
    return 2 * parentIndex + 1;
}

BinaryHeap::BinaryHeap() {}

BinaryHeap::~BinaryHeap() {}

void BinaryHeap::insert(int value)
{
    if (heap.size() > 0)
    {
        heap.push_back(value);
        int index = heap.size() - 1;
        this->bubbleUp(index);
    }
    else
        heap.push_back(value);
}

int BinaryHeap::getMin() const
{
    if (!heap.empty())
        return heap[0];
    return -1;
}

void BinaryHeap::deleteMin()
{
    if (heap.empty())
        return;

    heap[0] = heap.back();
    heap.pop_back();
    bubbleDown(0);
}

bool BinaryHeap::isEmpty() const
{
    return heap.empty();
}

void BinaryHeap::bubbleUp(int index)
{
    int parentIndex = getParentIndex(index);
    while (heap[index] < heap[parentIndex] && index >= 0)
    {
        // Swap values
        int aux = heap[parentIndex];
        heap[parentIndex] = heap[index];
        heap[index] = aux;

        // Update indexes
        index = parentIndex;
        parentIndex = getParentIndex(index);
    }
}

void BinaryHeap::bubbleDown(int index)
{
    int leftChild = getLeftChildIndex(index);
    int rightChild = getRightChildIndex(index);
    int minIndex = index;

    if (leftChild < heap.size() && heap[leftChild] < heap[minIndex])
        minIndex = leftChild;

    if (rightChild < heap.size() && heap[rightChild] < heap[minIndex])
        minIndex = rightChild;

    if (minIndex != index)
    {
        // Swap values
        int aux = heap[minIndex];
        heap[minIndex] = heap[index];
        heap[index] = aux;
        bubbleDown(minIndex);
    }
}
