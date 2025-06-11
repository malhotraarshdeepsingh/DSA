#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int sumTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    if (root->left || root->right)
    {
        root->val = leftSum + rightSum;
    }

    return root->val + leftSum + rightSum;
}

// Time Complexity: O(n), Space Complexity: O(n)