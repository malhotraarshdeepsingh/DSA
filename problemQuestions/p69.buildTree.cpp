#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(int in[], int pre[], int inStart, int inEnd, int preStart, int preEnd) {
    if (inStart > inEnd || preStart > preEnd) {
        return NULL;
    }

    TreeNode* root = new TreeNode(pre[preStart]);
    int rootIndex = -1;

    for (int i = inStart; i <= inEnd; i++) {
        if (in[i] == root->val) {
            rootIndex = i;
            break;
        }
    }

    int leftSize = rootIndex - inStart;

    root->left = buildTree(in, pre, inStart, rootIndex - 1, preStart + 1, preStart + leftSize);
    root->right = buildTree(in, pre, rootIndex + 1, inEnd, preStart + leftSize + 1, preEnd);

    return root;
}

void printInOrder(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main() {
    int in[] = {9, 3, 15, 20, 7};
    int pre[] = {3, 9, 20, 15, 7};
    int n = sizeof(in) / sizeof(in[0]);

    TreeNode* root = buildTree(in, pre, 0, n - 1, 0, n - 1);

    cout << "In-order traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}

// Time Complexity: O(n^2), Space Complexity: O(n)