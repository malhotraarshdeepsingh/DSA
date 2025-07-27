#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node
{
public:
    int val;
    Node *left, *right, *next;

    Node(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

Node *connect(Node *root)
{
    if (!root || root->left == nullptr)
        return root;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        Node *prev = nullptr;

        for (int i = 0; i < size; ++i)
        {
            Node *current = q.front();
            q.pop();

            if (current == nullptr)
            {
                if (size == 0)
                    break;

                q.push(nullptr);
            }
            else
            {
                if (prev)
                {
                    prev->next = current;
                }
                prev = current;

                if (current->left)
                {
                    q.push(current->left);
                }
                if (current->right)
                {
                    q.push(current->right);
                }
            }
        }
        prev->next = nullptr;
    }

    return root;
}