#include "testBinaryHeap.h"
#include "binaryHeap.h"
#include <iostream>

void testInsertAndGetMin();
void testDeleteMin();
void testIsEmpty();

void runAllTests()
{
    testInsertAndGetMin();
    testDeleteMin();
    testIsEmpty();
    std::cout << "All tests passed!" << std::endl;
}

void testInsertAndGetMin()
{
    BinaryHeap bh;
    bh.insert(5);
    bh.insert(2);
    bh.insert(8);
    bh.insert(1);

    if (bh.getMin() != 1)
        std::cerr << "testInsertAndGetMin failed" << std::endl;
}

void testDeleteMin()
{
    BinaryHeap bh;
    bh.insert(5);
    bh.insert(2);
    bh.insert(8);
    bh.insert(1);

    bh.deleteMin();

    if (bh.getMin() != 2)
        std::cerr << "testDeleteMin failed" << std::endl;
}

void testIsEmpty()
{
    BinaryHeap bh;

    if (!bh.isEmpty())
        std::cerr << "testIsEmpty failed (1)" << std::endl;

    bh.insert(5);

    if (bh.isEmpty())
        std::cerr << "testIsEmpty failed (2)" << std::endl;
}
