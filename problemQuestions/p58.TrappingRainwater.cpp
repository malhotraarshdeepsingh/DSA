#include <iostream>
#include <vector>

using namespace std;

// Method 1 : Prefix Array
int trap(vector<int> &height)
{
    int n = height.size();

    vector<int> left(n, 0), right(n, 0);

    left[0] = height[0];
    right[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], height[i]);

    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], height[i]);

    int water = 0;
    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - height[i];

    return water;
}

// Method 2 : Two Pointer Approach
int trap(vector<int> &height)
{
    int n = height.size();

    int left = 0, right = n - 1;
    int leftMax = 0, rightMax = 0;
    int water = 0;

    while (left < right)
    {
        if (height[left] < height[right])
        {
            if (height[left] >= leftMax)
                leftMax = height[left];
            else
                water += leftMax - height[left];

            left++;
        }
        else
        {
            if (height[right] >= rightMax)
                rightMax = height[right];
            else
                water += rightMax - height[right];

            right--;
        }
    }

    return water;
}

// Time Complexity: O(n)
// Space Complexity: O(n)