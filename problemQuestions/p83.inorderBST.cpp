#include <iostream>
#include <vector>
using namespace std;

class Node 
{
public:
    int val;
    Node *left, *right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> getPredSucc(Node *root, int target) 
{
    Node *curr = root;
    Node *pred = nullptr, *succ = nullptr;

    while(curr)
    {
        if(curr->val == target) 
        {
            if(curr->left) 
            {
                Node *temp = curr->left;
                while(temp->right) 
                {
                    temp = temp->right;
                }
                pred = temp;
            }
            if(curr->right) 
            {
                Node *temp = curr->right;
                while(temp->left) 
                {
                    temp = temp->left;
                }
                succ = temp;
            }
            break;
        } 
        else if(curr->val > target) 
        {
            succ = curr;
            curr = curr->left;
        } 
        else 
        {
            pred = curr;
            curr = curr->right;
        }
    }

    return {pred ? pred->val : -1, succ ? succ->val : -1};
}

int main() 
{
    Node *root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(30);
    root->left->left = new Node(5);
    root->left->right = new Node(15);
    root->right->right = new Node(35);

    int target = 10;
    vector<int> result = getPredSucc(root, target);
    
    cout << "Predecessor: " << result[0] << ", Successor: " << result[1] << endl;

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}