#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;

    // Stacks follow the principle of LIFO (Last In First Out) and are only accessible from one side of the container.
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl;

    // inbuilt functions are
    // push, emplace, top, pop, size, empty, swap

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop(); // removes the top element
    }
    cout << endl;

    stack<int> s1, s2;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    s2.swap(s1);

    cout << "Stack 1: ";
    while (!s1.empty())
    {
        cout << s1.top() << " ";
        s1.pop();
    }
    cout << endl;

    cout << "Stack 2: ";
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
    cout << endl;

    return 0;
}