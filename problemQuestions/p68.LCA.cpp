#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    Node *LCA(Node *root, Node *n1, Node *n2)
    {
        if (!root)
        {
            return nullptr;
        }

        if (root->data == n1->data || root->data == n2->data)
        {
            return root;
        }

        Node *left = LCA(root->left, n1, n2);
        Node *right = LCA(root->right, n1, n2);

        if (left && right)
        {
            return root;
        }

        return left ? left : right;
    }
};

// Time Complexity: O(N), Space Complexity: O(N)