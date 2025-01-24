#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *temp = head;

    int count = 0;
    while (count < k)
    {
        if (temp == NULL)
            return head;

        temp = temp->next;
    }

    // recursively call for rest of linked list
    ListNode *prevNode = reverseKGroup(temp->next, k);

    // reverse the current group
    temp = head, count = 0;
    while (count < k)
    {
        ListNode *nextNode = temp->next;
        temp->next = prevNode;

        prevNode = temp;
        temp = nextNode;
        
        count++;
    }
}