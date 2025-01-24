#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode *random;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *prev = NULL;

    while (first!=NULL && second!=NULL)
    {
        ListNode* third = second->next;

        second->next = first;
        first->next = third;

        if (prev!= NULL)
            prev->next = second;
        else
            head = second;

        prev = first;
        first = third;
        if (third!=NULL)
            second = third->next;
        else 
            second = NULL;
    }

    return head;
}
