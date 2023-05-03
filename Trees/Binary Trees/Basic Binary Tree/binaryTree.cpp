#include "binaryTree.h"
#include <queue>
#include <cmath>
#include <vector>

// HELPER FUNCTIONS

void dfs(TreeNode *node, std::vector<int> path, std::vector<std::vector<int>> &result)
{
    if (node->left == nullptr && node->right == nullptr)
    {
        result.push_back(path);
        return;
    }
    else
    {
        path.push_back(node->data);

        if (node->left != nullptr)
        {
            dfs(node->left, path, result);
        }

        if (node->right != nullptr)
        {
            dfs(node->right, path, result);
        }
    }
}

// Appends all children and grandChildren and family of node to q.
void emplaceChildren(std::queue<TreeNode *> q, TreeNode *node)
{
    if (!(node->right == nullptr && node->left == nullptr))
    {
        if (node->left != nullptr && node->right != nullptr)
        {
            q.emplace(node->left);
            q.emplace(node->right);
        }
        else
        {
            if (node->right == nullptr)
                q.emplace(node->left);

            if (node->left == nullptr)
                q.emplace(node->right);
        }
    }
}

// Appends all children and grandChildren and family of node to q.
void emplaceChildren(std::queue<std::pair<TreeNode *, bool>> q, TreeNode *node)
{
    if (!(node->right == nullptr && node->left == nullptr))
    {
        if (node->left != nullptr && node->right != nullptr)
        {
            q.emplace(std::pair<TreeNode *, bool>(node->left, true));
            q.emplace(std::pair<TreeNode *, bool>(node->right, false));
        }
        else
        {
            if (node->right == nullptr)
                q.emplace(std::pair<TreeNode *, bool>(node->left, true));

            if (node->left == nullptr)
                q.emplace(std::pair<TreeNode *, bool>(node->right, false));
        }
    }
}
///////////////////////////////////////////////

BinaryTree::~BinaryTree()
{
    std::queue<TreeNode *> q;
    q.emplace(this->root);
    emplaceChildren(q, this->root);
    TreeNode *toDelete;
    for (int i = 0; i < q.size(); i++)
    {
        toDelete = q.front();
        q.pop();
        delete toDelete;
    }
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
                newNode->parent = it;
            }
            else
            {
                if (it->right == nullptr)
                {
                    found = true;
                    it->right = newNode;
                    newNode->parent = it;
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
    this->lastNodeInserted = newNode;
    this->numOfNodes++;
}

void BinaryTree::remove(int value)
{
    if (this->size() != 0)
    {
        TreeNode *it = this->root;
        // Queue for checking nodes, if bool = true means node is leftChild, if
        // false node is right child.
        std::queue<std::pair<TreeNode *, bool>> q;
        int i = 0;
        bool removed = false;
        while (i < numOfNodes && !removed)
        {
            if (it->data == value)
            {
                removed = true;
                it->data = this->lastNodeInserted->data;
                TreeNode *toDelete = this->lastNodeInserted;
                updateLastNodeInserted();
                delete toDelete;
            }
            else
            {
                emplaceChildren(q, it);
                if (!q.empty())
                {
                    q.pop();
                    if (!q.empty())
                        it = q.front().first;
                }
                i++;
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
                if (it->left != nullptr)
                    q.emplace(it->left);
                if (it->right != nullptr)
                    q.emplace(it->right);
                if (!q.empty())
                    q.pop();
                i++;
            }
        }
        return found;
    }
    return false;
}

// Because of the way elements are inserted, removed and sorted in this binary tree,
// you only need to check or powers of 2 when computing the height.
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

// Because of the way elements are inserted, removed and sorted in this binary tree, its always balanced.
bool BinaryTree::isBalanced()
{
    return true;
}

// Assuming path can start anywhere and no node has negative values. (wrong implementation)
int BinaryTree::pathSum(int target)
{
    int numOfPaths = 0;
    if (this->size() == 0)
        return 0;
    else
    {
        std::queue<TreeNode *> q;
        q.emplace(this->root);
        emplaceChildren(q, this->root);

        TreeNode *it;
        for (int i = 0; i < q.size(); i++)
        {
            it = q.front();
            std::vector<std::vector<int>> paths = getAllPathsFromNode(it);
            q.pop();
            for (std::vector<int> path : paths)
            {
                int cumSum = 0;
                for (int value : path)
                {
                    cumSum += value;
                    if (cumSum == target)
                        numOfPaths++;
                    else
                    {
                        if (cumSum > target)
                            break;
                    }
                }
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
            emplaceChildren(q, it);
            if (!q.empty())
            {
                q.pop();
                if (!q.empty())
                    it = q.front();
            }
            i++;
        }
    }
}

// Only called from remove() function.
void BinaryTree::updateLastNodeInserted()
{
    TreeNode *parentOfLastNode = this->lastNodeInserted->parent;
    if (parentOfLastNode->left == this->lastNodeInserted)
    {
        parentOfLastNode->left = nullptr;
        this->lastNodeInserted = nullptr;
        std::queue<TreeNode *> q;
        emplaceChildren(q, this->root);
        this->lastNodeInserted = q.back();
    }
    else
    {
        parentOfLastNode->right = nullptr;
        this->lastNodeInserted = parentOfLastNode->left;
    }
}

std::vector<std::vector<int>> BinaryTree::getAllPathsFromNode(TreeNode *node) const
{
    std::vector<std::vector<int>> result;
    std::vector<int> path;

    dfs(node, path, result);

    return result;
};
