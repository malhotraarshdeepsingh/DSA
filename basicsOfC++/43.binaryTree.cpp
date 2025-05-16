#include <iostream>
#include <vector>

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

Node *buildTree(vector<int> &arr)
{
    if (arr.empty())
        return NULL;

    Node *root = new Node(arr[0]);
    vector<Node *> nodes;
    nodes.push_back(root);

    for (int i = 1; i < arr.size(); ++i)
    {
        if (arr[i] == -1)
        {
            return NULL; // -1 indicates no node
        }
        else
        {
            Node *newNode = new Node(arr[i]);
            root->left = buildTree(arr);
            root->right = buildTree(arr);
        }
    }

    return root;
}

int main()
{
    vector<int> arr = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};

    Node *root = buildTree(arr);

    return 0;
}