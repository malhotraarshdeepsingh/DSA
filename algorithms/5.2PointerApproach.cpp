#include <iostream>
#include <vector>
using namespace std;

// Brute force approach
int maxArea (vector<int> &height)
{

    int maxWater = 0;

    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int width = j - i;
            int min_height = min(height[i], height[j]);

            maxWater = max(maxWater, width * min_height);
        }
    }

    return maxWater;
    // Time complexity: O(n^2)
    // Space complexity: O(1)
    
}

// Two Pointer Approach
int maxAreaOptimized(vector<int> &height)
{

    int maxWater = 0;
    int left = 0, right = height.size() - 1;

    while (left < right)
    {
        int width = right - left;
        int min_height = min(height[left], height[right]);

        maxWater = max(maxWater, width * min_height);

        if (height[left] < height[right])
            left++;
        else
            right--;
    }

    return maxWater;
    // Time complexity: O(n)
    // Space complexity: O(1)

}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int max_area = maxArea(height);

    cout << "Maximum water that can be trapped is: " << max_area << endl;
}