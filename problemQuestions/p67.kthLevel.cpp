#include <iostream>

using namespace std;

void kthLevel(Node *root, int k)
{
    if (root == nullptr) {
        return;
    }
    
    if (k == 0) {
        cout << root->data << " ";
        return;
    }
    
    kthLevel(root->left, k - 1);
    kthLevel(root->right, k - 1);
}