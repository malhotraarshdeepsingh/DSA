#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to check if two binary trees are identical
bool isIdentical(Node *root1, Node *root2)
{
    if (!root1 && !root2)
        return true;

    if (!root1 || !root2)
        return false;

    if (root1->data != root2->data)
        return false;

    return isIdentical(root1->left, root2->left) && isIdentical(root1->right, root2->right);
}

// Function to check if a tree is a subtree of other tree
bool isSubtree(Node *root1, Node *root2)
{
    if (root1 == NULL || root2 == NULL)
        return root1 == root2; 

    if (root1->data == root2->data && isIdentical(root1, root2))
        return true;

    if (isIdentical(root1, root2))
        return true;

    return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}