// Queue works on principle of FIFO (First In First Out) and is only accessible from both ends of the container.
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    // same syntax as stack
    
    // Insert elements into queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    // Print all elements of queue
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}