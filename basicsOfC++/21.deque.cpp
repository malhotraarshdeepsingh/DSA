// Deque - Double Ended Queue
// Deque is a dynamic array that can be expanded or contracted on both ends (either end).
// Deque is a sequence container that allows insertion and deletion at both ends.
// Deque is similar to vector but more efficient in case of insertion and deletion at both ends.
// Deque is a combination of stack and queue.

#include<iostream>
#include<deque>

using namespace std;

int main() {
    deque<int> dq = {0};
    
    // Insertion at both ends 
    dq.push_front(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_back(4);
    
    cout << "Deque elements: ";
    for(int i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;
    
    // Deletion at both ends
    dq.pop_front();
    dq.pop_back();
    
    cout << "After deletion: ";
    for(int i = 0; i < dq.size(); i++)
        cout << dq[i] << " ";
    cout << endl;

    // all inbuilt functions work with deque
    // size, erase, clear, begin, end, rbegin, rend, insert, front, back, empty, remove, sort, reverse, unique, merge, splice, swap, assign, resize, push_front, push_back, pop_front, pop_back, max_size, remove_if
    
    return 0;
}