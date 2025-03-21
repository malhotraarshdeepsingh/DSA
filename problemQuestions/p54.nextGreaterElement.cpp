#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() 
{
    vector <int> arr = {6, 8, 0, 1, 3};

    vector <int> result(arr.size(), 0);
    stack <int> s;
    
    for (int i = v.size() - 1; i >= 0; i--){
        while (!s.empty() && s.top() <= arr[i])
            s.pop();
            
        if (s.empty())
            result.push_back(-1);
        else
            result.push_back(s.top());
            
        s.push(arr[i]);
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)