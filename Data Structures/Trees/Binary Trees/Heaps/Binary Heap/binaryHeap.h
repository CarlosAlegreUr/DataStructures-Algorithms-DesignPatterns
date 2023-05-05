#pragma once

#include <vector>

// Min heap in this case. (BinaryHeap can be a max-heap too that means that the root is the highest priority element instead
// of the lowest priority one as it's in min-heap implemented here.)
class BinaryHeap
{
public:
    BinaryHeap();
    ~BinaryHeap();

    void insert(int value);
    int getMin() const;
    void deleteMin();
    bool isEmpty() const;

private:
    // Root => heap[0]
    // Left child: 2 * index + 1
    // Right child: 2 * index + 2
    // Parent: (index - 1) / 2 (only the integer result of division)
    std::vector<int> heap;

    int getParentIndex(int childNodeIndex);
    int getRightChildIndex(int parentIndex);
    int getLeftChildIndex(int parentIndex);

    void bubbleUp(int index);
    void bubbleDown(int index);
};
