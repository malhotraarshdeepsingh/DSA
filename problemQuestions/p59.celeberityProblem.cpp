#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int celebrity(vector<vector<int>> &M)
{
    stack<int> s;

    for (int i = 0; i < M.size(); i++)
        s.push(i);

    while (s.size() > 1)
    {
        int A = s.top();
        s.pop();
        int B = s.top();
        s.pop();

        if (M[A][B] == 1)
            s.push(B);
        else
            s.push(A);
    }

    int candidate = s.top();
    s.pop();

    for (int i = 0; i < M.size(); i++)
    {
        if (i != candidate && (M[candidate][i] == 1 || M[i][candidate] == 0))
            return -1;
    }

    return candidate;
}

// Time Complexity: O(n)
// Space Complexity: O(n)