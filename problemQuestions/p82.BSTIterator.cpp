#include <iostream>
#include <stack>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator
{
public:
    stack<TreeNode *> s;

    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    void pushLeft(TreeNode *node)
    {
        while (node)
        {
            s.push(node);
            node = node->left;
        }
    }

    int next()
    {
        TreeNode *ans = s.top();
        s.pop();
        pushLeft(ans->right);
        return ans->val;
    }

    bool hasNext()
    {
        return !s.empty();
    }
};

// Time Complexity: O(h) for next() and O(1) for hasNext()
// Space Complexity: O(h)
