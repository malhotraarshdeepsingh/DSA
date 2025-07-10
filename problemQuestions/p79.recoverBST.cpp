#include <iostream>
#include <vector>
using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode* prev = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    void inorder(TreeNode* root)
    {
        if (!root) return;

        inorder(root->left);

        if (prev && prev->val > root->val)
        {
            if (!first)
                first = prev;
            second = root;
        }
        prev = root;

        inorder(root->right);
    }

    void recoverTree(TreeNode* root)
    {
        inorder(root);

        if (first && second)
        {
            swap(first->val, second->val);
        }
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)