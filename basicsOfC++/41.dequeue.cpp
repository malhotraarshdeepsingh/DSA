#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<int> dq;

    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    cout << dq.front() << endl; // 1
    cout << dq.back() << endl;  // 3

    dq.pop_front();
    cout << dq.front() << endl; // 2

    dq.pop_back();
    cout << dq.back() << endl; // 2

    return 0;
}