// Binary Search Tree Implementation in C++
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    unique_ptr<TreeNode> root;

    void insert(unique_ptr<TreeNode>& node, int val) {
        if (!node) {
            node = make_unique<TreeNode>(val);
        } else if (val < node->val) {
            insert(node->left, val);
        } else {
            insert(node->right, val);
        }
    }

    void inorderTraversal(const unique_ptr<TreeNode>& node, vector<int>& result) const {
        if (node) {
            inorderTraversal(node->left, result);
            result.push_back(node->val);
            inorderTraversal(node->right, result);
        }
    }

    bool search(const unique_ptr<TreeNode>& node, int val) const {
        if (!node) return false;
        if (node->val == val) return true;
        return val < node->val ? search(node->left, val) : search(node->right, val);
    }

    void clear(unique_ptr<TreeNode>& node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            node.reset();
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() {
        clear(root);
    }
    void insert(int val) {
        insert(root, val);
    }
    vector<int> inorderTraversal() const {
        vector<int> result;
        inorderTraversal(root, result);
        return result;
    }
    bool search(int val) const {
        return search(root, val);
    }
    void clear() {
        clear(root);
    }
    void print() const {
        vector<int> result = inorderTraversal();
        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    bst.insert(2);
    bst.insert(4);
    bst.insert(6);
    bst.insert(8);

    cout << "Inorder Traversal: ";
    bst.print();

    int searchValue = 4;
    cout << "Searching for " << searchValue << ": " 
         << (bst.search(searchValue) ? "Found" : "Not Found") << endl;

    searchValue = 10;
    cout << "Searching for " << searchValue << ": " 
         << (bst.search(searchValue) ? "Found" : "Not Found") << endl;

    return 0;
}