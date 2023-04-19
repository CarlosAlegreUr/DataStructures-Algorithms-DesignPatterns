#include "binaryTree.h"
#include <queue>
#include <cmath>
#include <vector>

BinaryTree::BinaryTree() : root(nullptr) {}

BinaryTree::~BinaryTree()
{
    // TODO: Implement destructor to delete all nodes
}

void BinaryTree::insert(int value)
{
    TreeNode *newNode = new TreeNode(value);
    if (this->size() != 0)
    {
        TreeNode *it = this->root;
        std::queue<TreeNode *> q;
        bool found = false;
        while (!found)
        {
            if (it->left == nullptr)
            {
                found = true;
                it->left = newNode;
            }
            else
            {
                if (it->right == nullptr)
                {
                    found = true;
                    it->right = newNode;
                }
                else
                {
                    q.emplace(it->left);
                    q.emplace(it->right);
                    q.pop();
                    it = q.front();
                }
            }
        }
    }
    else
        this->root = newNode;
    this->numOfNodes++;
}

// Not finished.
void BinaryTree::remove(int value)
{
    if (this->size() != 0)
    {
        TreeNode *it = this->root;
        std::queue<TreeNode *> q;
        int i = 0;
        bool removed = false;
        TreeNode *parentNode = it;
        while (i < numOfNodes && !removed)
        {
            if (it->left != nullptr && it->right != nullptr)
            {
                if (it->data != value)
                {
                    q.emplace(it->left);
                    q.emplace(it->right);
                    q.pop();
                    it = q.front();
                    i++;
                }
                else
                {

                    removed = true;
                }
            }
            else
            {
                if (it->right == nullptr && it->left != nullptr)
                {
                    if (it->data != value)
                    {
                        q.emplace(it->left);
                        q.pop();
                        it = q.front();
                        i++;
                    }
                    else
                    {
                        // Restructure the tree, left childs alwas take palce of the parent.
                        removed = true;
                    }
                }
                else
                {
                    if (it->data == value)
                    {
                        removed = true;
                    }
                }
            }
        }
    }
}

bool BinaryTree::search(int value)
{
    if (this->size() != 0)
    {
        TreeNode *it = this->root;
        std::queue<TreeNode *> q;
        bool found = false;
        int i = 0;
        while (!found && i < numOfNodes)
        {
            if (it->data == value)
                found = true;
            else
            {
                q.emplace(it->left);
                q.emplace(it->right);
                q.pop();
                i++;
            }
        }
        return found;
    }
    return false;
}

int BinaryTree::height()
{
    if (this->size() == 0 || this->size() == 1)
        return 0;
    else
    {
        bool found = false;
        int exponent = 1;
        while (found == false)
        {
            if (numOfNodes >= pow(2, exponent) && numOfNodes <= pow(2, exponent + 1))
                found = true;
            else
                exponent++;
        }
        return exponent;
    }
}

int BinaryTree::size()
{
    return this->numOfNodes;
}

// Missunderstood what balanced means.
bool BinaryTree::isBalanced()
{
    return (pow(2, this->height()) == this->numOfNodes);
}

// Assuming path can start anywhere and no node has negative values. (wrong implementation)
int BinaryTree::pathSum(int target)
{
    int numOfPaths = 0;
    if (this->size() == 0)
        return 0;
    else
    {
        TreeNode *it = this->root;
        std::queue<TreeNode *> q;
        int i = 0;
        while (i < numOfNodes)
        {
            if (it->left != nullptr && it->right != nullptr)
            {
                q.emplace(it->left);
                q.emplace(it->right);

                std::queue<TreeNode *> q2;
                q2.emplace(it);

                int cumSum = it->data;
                TreeNode *it2 = it;
                while (!q2.empty())
                {
                    bool pathFound = false;
                    if ((cumSum + it2->left->data) <= target)
                    {
                        q2.emplace(it2->left);
                        if ((cumSum + it2->left->data) == target)
                        {
                            numOfPaths++;
                            pathFound = true;
                        }
                    }

                    if ((cumSum + it2->right->data) <= target)
                    {
                        q2.emplace(it2->right);
                        if ((cumSum + it2->right->data) == target)
                        {
                            numOfPaths++;
                            pathFound = true;
                        }
                    }

                    q2.pop();
                    if (!q2.empty())
                        it2 = q2.front();

                    if (pathFound)
                        cumSum = it2->data;
                    else
                        cumSum += it2->data;
                }

                q.pop();
                it = q.front();
                i++;
            }
        }
    }
    return numOfPaths;
}

void BinaryTree::levelOrderTraversal()
{
    if (this->size() != 0)
    {
        TreeNode *it = this->root;
        std::queue<TreeNode *> q;
        int i = 0;
        while (i < numOfNodes)
        {
            if (it->left != nullptr && it->right != nullptr)
            {
                q.emplace(it->left);
                q.emplace(it->right);
                q.pop();
                it = q.front();
                i++;
            }
            else
            {
                if (it->right == nullptr && it->left != nullptr)
                {
                    q.emplace(it->left);
                    q.pop();
                    it = q.front();
                    i++;
                }
            }
        }
    }
}
