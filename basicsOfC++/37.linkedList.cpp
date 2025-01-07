#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    List()
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

    void push_front(int value)
    {
        Node *newNode = new Node(value); // This will create a new node with dynamic memory and will work
        // Node newNode = Node(value); // This will create a new node with static memory and will not work
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int value)
    {
        Node *newNode = new Node(value);
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
            return;

        Node *temp = head;
        head = head->next;

        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
            return;

        if (head->next == NULL)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
            temp = temp->next;

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void insert(int value, int position)
    {
        Node *newNode = new Node(value);
        
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else if (position == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }
        else
        {
            Node *temp = head;
            for (int i = 0; i < position - 1; i++)
                temp = temp->next;

            newNode->next = temp->next;
            temp->next = newNode;

            if (newNode->next == NULL)
                tail = newNode;
        }
    }

    int search(int key)
    {
        Node *temp = head;
        int index = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
                return index;

            temp = temp->next;
            index++;
        }

        return -1; // Key not found
    }
};

int main()
{
    List myList;

    myList.push_front(5);
    myList.push_front(3);
    myList.push_front(1);

    myList.push_back(7);
    myList.push_back(9);
    myList.push_back(11);

    myList.print(); // Output: 1 3 5 7 9 11

    myList.pop_front();
    myList.pop_back();

    myList.print(); // Output: 3 5 7 9

    myList.insert(4, 1);
    myList.insert(6, 3);
    myList.insert(2, 0);

    myList.print(); // Output: 2 3 4 5 6 7 9

    int searchResult = myList.search(5);
    cout << "Index: " << (searchResult) << endl; // Output: Index: 3

    return 0;
}