#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void binaryTreePaths(TreeNode *root, string path, vector<string> &paths)
{
    if (root == NULL)
    {
        return;
    }

    path += to_string(root->val);

    if (root->left == NULL && root->right == NULL)
    {
        paths.push_back(path);
    }
    else
    {
        path += "->";
        binaryTreePaths(root->left, path, paths);
        binaryTreePaths(root->right, path, paths);
    }
}