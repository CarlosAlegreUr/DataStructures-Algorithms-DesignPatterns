#include "testBinaryTree.h"
#include <iostream>
#include <cassert>

void TestBinaryTree::runAllTests()
{
    testInsert();
    testRemove();
    testSearch();
    testHeight();
    testSize();
    testIsBalanced();
    testPathSum();
    testLevelOrderTraversal();
}

void TestBinaryTree::testInsert()
{
    BinaryTree bt;

    bt.insert(1);
    assert(bt.size() == 1);
    assert(bt.height() == 0);

    bt.insert(2);
    assert(bt.size() == 2);
    assert(bt.height() == 1);

    bt.insert(3);
    assert(bt.size() == 3);
    assert(bt.height() == 1);

    bt.insert(4);
    assert(bt.size() == 4);
    assert(bt.height() == 2);

    bt.insert(5);
    assert(bt.size() == 5);
    assert(bt.height() == 2);

    bt.insert(6);
    assert(bt.size() == 6);
    assert(bt.height() == 2);

    bt.insert(7);
    assert(bt.size() == 7);
    assert(bt.height() == 2);

    bt.insert(8);
    assert(bt.size() == 8);
    assert(bt.height() == 3);

    std::cout << "All testInsert() tests passed." << std::endl;
}

void TestBinaryTree::testRemove()
{
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    bt.remove(3);
    assert(bt.size() == 6);
    assert(bt.search(3) == false);

    bt.remove(1);
    assert(bt.size() == 5);
    assert(bt.search(1) == false);

    std::cout << "All testRemove() tests passed." << std::endl;
}

void TestBinaryTree::testSearch()
{
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    assert(bt.search(1) == true);
    assert(bt.search(3) == true);
    assert(bt.search(7) == true);
    assert(bt.search(8) == false);

    std::cout << "All testSearch() tests passed." << std::endl;
}

void TestBinaryTree::testHeight()
{
    BinaryTree bt;

    assert(bt.height() == 0);

    bt.insert(1);
    assert(bt.height() == 0);

    bt.insert(2);
    assert(bt.height() == 1);

    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    assert(bt.height() == 3);

    std::cout << "All testHeight() tests passed." << std::endl;
}

void TestBinaryTree::testSize()
{
    BinaryTree bt;

    assert(bt.size() == 0);

    bt.insert(1);
    assert(bt.size() == 1);

    bt.insert(2);
    assert(bt.size() == 2);

    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    assert(bt.size() == 7);

    std::cout << "All testSize() tests passed." << std::endl;
}

void TestBinaryTree::testIsBalanced()
{
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    assert(bt.isBalanced() == true);

    BinaryTree bt2;

    bt2.insert(1);
    bt2.insert(2);
    bt2.insert(3);
    bt2.insert(4);
    bt2.insert(5);
    bt2.insert(6);

    assert(bt2.isBalanced() == true);

    std::cout << "All testIsBalanced() tests passed." << std::endl;
}

void TestBinaryTree::testPathSum()
{
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    assert(bt.pathSum(10) == 2); // Paths: 1->2->3->4 and 1->2->5
    assert(bt.pathSum(8) == 1);  // Path: 1->3->4
    assert(bt.pathSum(15) == 0);

    std::cout << "All testPathSum() tests passed." << std::endl;
}

void TestBinaryTree::testLevelOrderTraversal()
{
    BinaryTree bt;

    bt.insert(1);
    bt.insert(2);
    bt.insert(3);
    bt.insert(4);
    bt.insert(5);
    bt.insert(6);
    bt.insert(7);

    bt.levelOrderTraversal(); // Should print: 1 2 3 4 5 6 7

    std::cout << "All testLevelOrderTraversal() tests passed." << std::endl;
}
