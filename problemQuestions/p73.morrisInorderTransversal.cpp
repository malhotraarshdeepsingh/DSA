#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void morrisInorderTraversal(TreeNode *root)
{
    TreeNode *current = root;
    TreeNode *predecessor;

    while (current)
    {
        if (!current->left)
        {
            cout << current->val << " ";
            current = current->right;
        }
        else
        {
            predecessor = current->left;
            while (predecessor->right && predecessor->right != current)
            {
                predecessor = predecessor->right;
            }

            if (!predecessor->right)
            {
                predecessor->right = current;
                current = current->left;
            }
            else
            {
                predecessor->right = NULL;
                cout << current->val << " ";
                current = current->right;
            }
        }
    }
}