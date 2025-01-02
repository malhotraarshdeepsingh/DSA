// priority queue is just a sorted queue of elements that either follow max heap or min heap property.
// By default, priority queue in C++ is a max heap.

#include <queue>
#include <iostream>

using namespace std;

int main()
{
    // create a max heap priority queue
    priority_queue<int> pq;

    // syntax for min heap priority
    // priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(10);
    pq.push(20);
    pq.push(5);
    pq.push(15);

    cout << "Size of the priority queue: " << pq.size() << endl;

    cout << "Top element of the priority queue: " << pq.top() << endl;

    pq.pop();

    cout << "Size of the priority queue after popping: " << pq.size() << endl;
    cout << "Top element of the priority queue after popping: " << pq.top() << endl;

    // inbuilt functions are
    // push, pop, top, size, empty, swap, emplace
    // push and pop has O(log n) time complexity because it sorts before inserting
    // top has O(1) time complexity

    return 0;
}