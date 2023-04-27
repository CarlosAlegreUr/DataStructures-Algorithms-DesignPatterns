#pragma once

#include <vector>
#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr), parent(nullptr) {}
    TreeNode(int value, TreeNode *parent) : data(value), left(nullptr), right(nullptr), parent(parent) {}
};

class BinaryTree
{
public:
    BinaryTree() : root(nullptr), numOfNodes(0), lastNodeInserted(nullptr){};
    ~BinaryTree();

    void insert(int value);
    void remove(int value);
    bool search(int value);
    int height();
    int size();
    bool isBalanced();
    int pathSum(int target);
    void levelOrderTraversal();

private:
    void updateLastNodeInserted();
    std::vector<std::vector<int>> getAllPathsFromNode(TreeNode *node) const;
    TreeNode *root;
    TreeNode *lastNodeInserted;
    int numOfNodes;
};
