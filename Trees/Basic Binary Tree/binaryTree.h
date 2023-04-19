#pragma once

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree
{
public:
    BinaryTree() : root(nullptr), numOfNodes(0){};
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
    TreeNode *root;
    int numOfNodes;
};
