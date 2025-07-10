#include <iostream>

using namespace std;

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Info
{
public:
    int size, min, max;

    Info(int s, int mn, int mx)
    {
        size = s;
        min = mn;
        max = mx;
    }
};

Info helper(TreeNode *root)
{
    if (!root)
        return Info(0, INT_MAX, INT_MIN);

    Info leftInfo = helper(root->left);
    Info rightInfo = helper(root->right);

    if (root->val > leftInfo.max && root->val < rightInfo.min)
    {
        int size = leftInfo.size + rightInfo.size + 1;
        int minVal = min(root->val, leftInfo.min);
        int maxVal = max(root->val, rightInfo.max);
        return Info(size, minVal, maxVal);
    }
}

int largestBSTinBT(TreeNode *root)
{
    Info info = helper(root);
    return info.size;
}

// Time Complexity: O(n), Space Complexity: O(n)