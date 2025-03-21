#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

vector <int> nextGreaterElement(vector <int> arr1, vector <int> arr2)
{
    vector <int> result;
    stack <int> s;
    unordered_map <int, int> m;
    
    for (int i = arr2.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= arr2[i])
            s.pop();
            
        if (s.empty())
            m[arr2[i]] = -1;
        else
            m[arr2[i]] = s.top();
            
        s.push(arr2[i]);
    }
    
    for (int i = 0; i < arr1.size(); i++)
    {
        result.push_back(m[arr1[i]]);
    }
    
    return result;
}

// Time Complexity: O(n)
// Space Complexity: O(n)