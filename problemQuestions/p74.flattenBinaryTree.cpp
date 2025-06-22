#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void flatten(TreeNode* root) {
    if (!root) return;

    flatten(root->left);
    flatten(root->right);

    TreeNode* temp = root->right;

    root->right = root->left;
    root->left = NULL;

    TreeNode* current = root;
    while (current->right) {
        current = current->right;
    }
    current->right = temp;
}

int main() {

    // Example usage:
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->right = new TreeNode(6);

    flatten(root);

    TreeNode* current = root;
    while (current) {
        cout << current->val << " ";
        current = current->right;
    }
    
    return 0;
}
