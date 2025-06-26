#include <iostream>
#include <limits.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int minDiffInBST(TreeNode *root)
{
    if (!root)
        return INT_MAX;

    int ans = INT_MAX;

    if (root->left)
    {
        int leftMin = minDiffInBST(root->left);
        ans = min(ans, leftMin);
    }

    if (prev != NULL)
    {
        ans = min(ans, abs(root->val - prev->val));
    }

    prev = root;

    if (root->right)
    {
        int rightMin = minDiffInBST(root->right);
        ans = min(ans, rightMin);
    }

    return ans;
}