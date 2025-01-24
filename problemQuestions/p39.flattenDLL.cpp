#include <iostream>

using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node *child;
};

Node *flatten(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *cur = head;
    while (cur != NULL)
    {
        if (cur->child != NULL)
        {
            // flatten child nodes
            Node *next = cur->next;
            cur->next = flatten(cur->child);

            cur->next->prev = cur;
            cur->child = NULL;

            // find tail
            while (cur->next != NULL)
                cur = cur->next;

            // attach node to next ptr
            if (next != NULL)
            {
                next->prev = cur;
                cur->next = next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }

    return head;
}