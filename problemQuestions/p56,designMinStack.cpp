#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// Method 1: Using a stack of pair of integers

class MinStack {
    stack <pair<int, int>> s;

public:
    MinStack() {
    }

    void push(int val) {
        if (s.empty())
            s.push({val, val});
        else
            s.push({val, min(val, s.top().second)});
    }

    void pop() {
        s.pop();
    }

    int top() {
        return s.top().first;
    }

    int getMin() {
        return s.top().second;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(n)


// Method 2: Using stack and a separate variable

class MinStack {
    stack <int> s;
    int minVal = INT_MAX;

public:
    MinStack() {
    }

    void push(int val) {
        if (val <= minVal)
        {
            s.push(minVal);
            minVal = val;
        }
        s.push(val);
    }

    void pop() {
        if (s.top() == minVal)
        {
            s.pop();
            minVal = s.top();
            s.pop();
        }
        else
            s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minVal;
    }
};

// Time Complexity: O(1)
// Space Complexity: O(1)