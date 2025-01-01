#include <iostream>
#include <list>
using namespace std;

int main()
{
    // Lists are sequence containers that allow non-contiguous memory allocation. As compared to vector, list has slow traversal, but once a position has been found, insertion and deletion are quick. Normally, when we say a List, we talk about a doubly linked list.

    list<int> l;

    // Insert elements at the end
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    // Insert elements at the beginning
    l.push_front(5);
    l.push_front(4);
    l.push_front(3);

    for (int val : l) {
        cout << val << " ";
    }
    cout << endl;

    // Remove elements from the end
    l.pop_back();
    cout << "After removing last element: ";
    for (int val : l) {
        cout << val << " ";
    }
    cout << endl;
    
    // Remove elements from the beginning
    l.pop_front();
    cout << "After removing first element: ";
    for (int val : l) {
        cout << val << " ";
    }
    cout << endl;

    // all inbuilt functions of list
    // size, erase, clear, begin, end, rbegin, rend, insert, front, back, empty, remove, sort, reverse, unique, merge, splice, swap, assign, resize, push_front, push_back, pop_front, pop_back, max_size, remove_if
    
    return 0;
}