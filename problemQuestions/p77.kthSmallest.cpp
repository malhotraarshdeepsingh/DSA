#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int prevOrder = 0;
int leftAns = -1;
int rightAns = -1;

int kthSmallest(TreeNode *root, int k)
{
    if (!root)
        return -1;

    if (root->left != NULL)
    {
        leftAns = kthSmallest(root->left, k);
        if (leftAns != -1)
            return leftAns;
    }

    if (prevOrder + 1 == k)
    {
        return root->val;
    }

    prevOrder++;

    if (root->right != NULL)
    {
        rightAns = kthSmallest(root->right, k);
        if (rightAns != -1)
            return rightAns;
    }

    return -1;
}