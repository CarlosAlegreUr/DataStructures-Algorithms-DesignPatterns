#include <iostream>
#include <cassert>
#include "testBinaryTree.h"
#include "binaryTree.h"

void testInsertAndSearch();
void testRemove();
void testHeight();
void testSize();
void testIsBalanced();
void testPathSum();
void testLevelOrderTraversal();

void runAllBinaryTreeTests()
{
    testInsertAndSearch();
    testRemove();
    testHeight();
    testSize();
    testIsBalanced();
    testPathSum();
    testLevelOrderTraversal();
    std::cout << "All BinaryTree tests passed!" << std::endl;
}

void testInsertAndSearch()
{
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);

    assert(tree.search(5));
    assert(tree.search(3));
    assert(tree.search(7));
    assert(!tree.search(1));
}

void testRemove()
{
    // You should implement this test based on your remove() method implementation.
}

void testHeight()
{
    BinaryTree tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);

    assert(tree.height() == 2);

    tree.insert(1);
    assert(tree.height() == 3);
}

void testSize()
{
    BinaryTree tree;
    assert(tree.size() == 0);

    tree.insert(5);
    assert(tree.size() == 1);

    tree.insert(3);
    assert(tree.size() == 2);

    tree.insert(7);
    assert(tree.size() == 3);
}

void testIsBalanced()
{
    // You should implement this test based on your isBalanced() method implementation.
}

void testPathSum()
{
    // You should implement this test based on your pathSum() method implementation.
}

void testLevelOrderTraversal()
{
    // You should implement this test based on your levelOrderTraversal() method implementation.
}
