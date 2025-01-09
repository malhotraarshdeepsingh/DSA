#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* copyListNode(ListNode *head)
{
    if (head == NULL)
        return NULL;

    unordered_map<ListNode*, ListNode*> map;

    ListNode *newHead = new ListNode(head->val);
    ListNode *newNode = newHead;
    ListNode *temp = head->next;

    while (temp != NULL)
    {
        ListNode *copyNode = new ListNode(temp->val);
        map[temp] = copyNode;
        newNode->next = copyNode;

        temp = temp->next;
        newNode = newNode->next;
    }

    temp = head;
    newNode = newHead;

    while (temp != NULL)
    {
        newNode->random = map[temp->random];
        temp = temp->next;
        newNode = newNode->next;
    }

    return newHead;
}