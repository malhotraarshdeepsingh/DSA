#include <iostream>
#include <vector>

using namespace std;

class Node 
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        data = data;
        next = NULL;
    }
};

class Queue
{
    Node *head, *tail;

public:
    Queue()
    {
        head = tail = NULL;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;

        if (head == NULL)
            tail = NULL;

        delete temp;
    }

    int front()
    {
        if (head == NULL)
            return -1;

        return head->data;
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl; // 1

    q.pop();
    cout << q.front() << endl; // 2

    q.pop();
    cout << q.front() << endl; // 3

    q.pop();
    cout << q.front() << endl; // -1

    return 0;
}

// Time Complexity: O(1) for all operations
// Space Complexity: O(n)