#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <int> previousSmallerElement(vector <int> arr)
{
    vector <int> result;
    stack <int> s;
    
    for (int i = 0; i < arr.size(); i++)
    {
        while (!s.empty() && s.top() >= arr[i])
            s.pop();
            
        if (s.empty())
            result.push_back(-1);
        else
            result.push_back(s.top());
            
        s.push(arr[i]);
    }
    
    return result;
}

int main() 
{
    vector <int> arr = {4, 5, 2, 10, 8};
    
    vector <int> result = previousSmallerElement(arr);
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
    
}

// Time Complexity: O(n)
// Space Complexity: O(n)