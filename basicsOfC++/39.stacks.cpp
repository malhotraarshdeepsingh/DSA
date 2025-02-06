#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Stack 
{
    vector <int> v;

public:
    void push(int data)
    {
        v.push_back(data);
    }

    void pop()
    {
        if (!v.empty())
        {
            v.pop_back();
        }
    }

    int top()
    {
        if (!v.empty())
        {
            return v[v.size() - 1];
        }

        return -1;
    }

    bool empty()
    {
        return v.empty();
    }
};

int main()
{
    // Stack s;
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.top() << endl; // 3

    s.pop();
    cout << s.top() << endl; // 2

    s.pop();
    cout << s.top() << endl; // 1

    s.pop();
    cout << s.top() << endl; // -1

    cout << s.empty() << endl; // 1

    return 0;
}