#include <iostream>
#include <stack>

using namespace std;

bool isValid (string str)
{
    stack <char> s;

    for (char c : str)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else
        {
            if (s.empty())
            {
                return false;
            }

            char topChar = s.top();
            s.pop();

            if ((c == ')' && topChar != '(') || (c == '}' && topChar != '{') || (c == ']' && topChar != '['))
            {
                return false;
            }
        }
    }

    return s.empty();
}

// Time Complexity: O(n)
// Space Complexity: O(n)