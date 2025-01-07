#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int subArraySum(vector<int>& arr, int k)
{
    int n = arr.size();
    int count = 0;
    vector<int> prefixSum(n, 0);

    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++)
        prefixSum[i] = prefixSum[i - 1] + arr[i];

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (prefixSum[i] == k)
            count++;
        
        int val = prefixSum[i] - k;

        if (m.find(val) != m.end())
            count += m[val];

        if (m.find(prefixSum[i]) == m.end())
            m[prefixSum[i]] = 0;

        m[prefixSum[i]]++;
    
    }
    
    return count;
}

// Time Complexity :- O(n)
// Space Complexity :- O(n)