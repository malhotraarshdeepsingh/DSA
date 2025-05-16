#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node* buildTreeHelper(const vector<int>& arr, int& index) {
    if (index >= arr.size() || arr[index] == -1) {
        index++; 
        return NULL;
    }

    Node* newNode = new Node(arr[index++]);
    newNode->left = buildTreeHelper(arr, index);
    newNode->right = buildTreeHelper(arr, index);

    return newNode;
}

Node* buildTree(const vector<int>& arr) {
    int index = 0;
    return buildTreeHelper(arr, index);
}

void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node* root = buildTree(arr);

    if (root) {
        cout << "Binary Tree built successfully." << endl;
        cout << "Root node value: " << root->data << endl;
        cout << "Left child of root: " << (root->left ? to_string(root->left->data) : "NULL") << endl;
        cout << "Right child of root: " << (root->right ? to_string(root->right->data) : "NULL") << endl;

        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    } else {
        cout << "Tree is empty." << endl;
    }

    return 0;
}
