#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void maxWidthBinaryTree(TreeNode *root)
{
    queue<pair<TreeNode *, unsigned long long>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (!q.empty())
    {
        int size = q.size();
        unsigned long long leftmost = q.front().second;
        unsigned long long rightmost = q.back().second;

        maxWidth = max(maxWidth, (int)(rightmost - leftmost + 1));

        for (int i = 0; i < size; i++)
        {
            TreeNode *node = q.front().first;
            q.pop();

            if (node->left)
            {
                q.push({node->left, 2 * q.front().second + 1});
            }
            if (node->right)
            {
                q.push({node->right, 2 * q.front().second + 1});
            }
        }
    }

    cout << "Maximum width of the binary tree: " << maxWidth << endl;
}

// Time Complexity: O(n), Space Complexity: O(n)