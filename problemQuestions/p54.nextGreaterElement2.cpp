#include <iostream>
#include <stack>
#include <vector>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> s;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[s.top()] <= nums[i % n])
            s.pop();

        if (i < n)
            res[i] = s.empty() ? -1 : nums[s.top()];

        s.push(i % n);
    }

    return res;
}

// Time Complexity: O(n)
// Space Complexity: O(n)