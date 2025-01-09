#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = prev = NULL;
    }
};

class DoublyLinkedList
{
    Node *head;
    Node *tail;

public:
    DoublyLinkedList()
    {
        head = tail = NULL;
    }

    void print()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;
        head->prev = NULL;

        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
            return;

        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;

        delete temp;
    }
};

int main()
{
    DoublyLinkedList list;

    list.push_front(5);
    list.push_front(10);
    list.push_front(15);

    list.push_back(20);
    list.push_back(25);
    list.push_back(30);

    list.pop_front();
    list.pop_back();

    list.print();
    return 0;
}