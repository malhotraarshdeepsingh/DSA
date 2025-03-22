#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    vector<int> left(n, 0), right(n, 0);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();

        right[i] = s.empty() ? n : s.top();
        s.push(i);
    }

    while (!s.empty())
        s.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && heights[s.top()] >= heights[i])
            s.pop();

        s.push(i);
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++)
        maxArea = max(maxArea, heights[i] * (right[i] - left[i] - 1));

    return maxArea;
}

// Time Complexity: O(n)
// Space Complexity: O(n)