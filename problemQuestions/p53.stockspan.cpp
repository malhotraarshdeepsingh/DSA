#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() 
{
    vector <int> v = {100, 80, 60, 70, 60, 75, 85};

    vector <int> result(v.size(), 0);
    stack <int> s;
    
    for (int i = v.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && s.top() <= v[i])
            s.pop();
            
        if (s.empty())
            result[i] = i + 1;
        else
           result[i] = i - s.top(); 
            
        s.push(v[i]);
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