#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) 
{
    stack <char> st;
    
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            st.push(s[i]);
        else
        {
            if (st.empty())
                return false;
            else if (s[i] == ')' && st.top() != '(')
                return false;
            else if (s[i] == '}' && st.top() != '{')
                return false;
            else if (s[i] == ']' && st.top() != '[')
                return false;
            else
                st.pop();
        }
    }
    
    return st.empty();
}

// Time Complexity: O(n)
// Space Complexity: O(n)