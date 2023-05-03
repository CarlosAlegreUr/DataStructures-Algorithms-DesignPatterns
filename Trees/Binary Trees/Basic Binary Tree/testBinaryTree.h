#pragma once
#include "binaryTree.h"

class TestBinaryTree
{
public:
    static void runAllTests();

private:
    static void testInsert();
    static void testRemove();
    static void testSearch();
    static void testHeight();
    static void testSize();
    static void testIsBalanced();
    static void testPathSum();
    static void testLevelOrderTraversal();
};
