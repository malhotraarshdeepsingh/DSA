#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);

    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
}

Node *buildBST(vector<int> arr)
{
    Node *root = nullptr;

    for (int val : arr)
    {
        root = insert(root, val);
    }

    return root;
}

void inorderTraversal(Node *root, vector<int> &arr)
{
    if (!root)
        return;

    inorderTraversal(root->left, arr);
    arr.push_back(root->data);
    inorderTraversal(root->right, arr);
}

Node *buildBSTfromSorted(vector<int> arr, int start, int end)
{
    if (start > end)
        return nullptr;

    int mid = start + (end - start) / 2;
    Node *node = new Node(arr[mid]);

    node->left = buildBSTfromSorted(arr, start, mid - 1);
    node->right = buildBSTfromSorted(arr, mid + 1, end);

    return node;
}

Node *mergeBSTs(Node *root1, Node *root2)
{
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    vector<int> arr1, arr2;

    inorderTraversal(root1, arr1);
    inorderTraversal(root2, arr2);

    vector<int> temp;

    int i = 0, j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            temp.push_back(arr1[i]);
            i++;
        }
        else
        {
            temp.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size())
    {
        temp.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size())
    {
        temp.push_back(arr2[j]);
        j++;
    }

    return buildBSTfromSorted(temp, 0, temp.size() - 1);
}

int main()
{
    vector<int> arr1 = {3, 1, 4};
    vector<int> arr2 = {5, 2, 6};

    Node *root1 = buildBST(arr1);
    Node *root2 = buildBST(arr2);

    Node *mergedRoot = mergeBSTs(root1, root2);

    // Output merged BST (inorder traversal)
    cout << "Merged BST Inorder: ";
    if (mergedRoot)
    {
        cout << mergedRoot->data << " ";
        if (mergedRoot->left)
            cout << mergedRoot->left->data << " ";
        if (mergedRoot->right)
            cout << mergedRoot->right->data << " ";
    }
    cout << endl;

    return 0;
}