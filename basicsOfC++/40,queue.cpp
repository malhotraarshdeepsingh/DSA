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


// Implementing Stack using Queue
class Stack
{
public:
    queue<int> q1, q2;

    Stack()
    {
    }

    void push(int data)
    {
        q2.push(data);

        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop()
    {
        if (!q1.empty())
            q1.pop();
    }

    int top()
    {
        if (!q1.empty())
            return q1.front();

        return -1;
    }
};

// Implementing Queue using Stack
class Queue
{
public:
    stack<int> s1, s2;

    Queue()
    {
    }

    void push(int data)
    {
        s1.push(data);
    }

    void pop()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty())
            s2.pop();
    }

    int front()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty())
            return s2.top();

        return -1;
    }
};