#include <iostream>
using namespace std;

class CircularDeque
{
    int *arr;
    int currSize, cap, front, rear;

public:
    CircularDeque(int cap)
    {
        arr = new int[cap];
        currSize = 0;
        cap = cap;
        front = 0;
        rear = cap - 1;
    }

    void insertFront(int val)
    {
        if (isFull())
            return;

        front = (front - 1 + cap) % cap;
        arr[front] = val;
        currSize++;
    }

    void insertLast(int val)
    {
        if (isFull())
            return;

        rear = (rear + 1) % cap;
        arr[rear] = val;
        currSize++;
    }

    void deleteFront()
    {
        if (isEmpty())
            return;

        front = (front + 1) % cap;
        currSize--;
    }

    void deleteLast()
    {
        if (isEmpty())
            return;

        rear = (rear - 1 + cap) % cap;
        currSize--;
    }

    int getFront()
    {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int getRear()
    {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    bool isEmpty()
    {
        return currSize == 0;
    }

    bool isFull()
    {
        return currSize == cap;
    }
};

int main()
{
    CircularDeque dq(3);

    dq.insertFront(1);
    dq.insertFront(2);
    dq.insertLast(3);

    cout << dq.getFront() << endl; // 2
    cout << dq.getRear() << endl;  // 3

    dq.deleteFront();
    cout << dq.getFront() << endl; // 1

    dq.deleteLast();
    cout << dq.getRear() << endl; // 1

    return 0;
}

// Time Complexity: O(1)
// Space Complexity: O(n)