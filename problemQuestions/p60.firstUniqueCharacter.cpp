#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int firstUniqueCharacter(string s)
{
    queue<char> q;
    unordered_map<char, int> mp;

    for (char c : s)
    {
        if (mp.find(c) == mp.end())
        {
            q.push(c);
            mp[c] = 1;
        }
        else
        {
            mp[c]++;
            while (!q.empty() && mp[q.front()] > 1)
                q.pop();
        }
    }

    return q.empty() ? -1 : q.front();
}

// Time Complexity: O(n)
// Space Complexity: O(n)