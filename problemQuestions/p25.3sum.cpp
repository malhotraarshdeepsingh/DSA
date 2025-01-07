#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> uniqueTriplets;

    for (int i = 0; i < n; i++)
    {
        int target = -nums[i];
        set<int> s;

        for (int j = i + 1; j < n; j++)
        {
            if (s.find(target - nums[j]) != s.end())
            {
                vector<int> trip = {nums[i], nums[j], target - nums[j]};
                sort(trip.begin(), trip.end());
                uniqueTriplets.insert(trip);
            }

            s.insert(nums[j]);
        }
    }

    vector<vector<int>> result(uniqueTriplets.begin(), uniqueTriplets.end());
    return result;
}

// most optimized implementation
vector<vector<int>> threeSumOptimized(vector<int> &nums)
{
    int n = nums.size();
    set<vector<int>> uniqueTriplets;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int left = i + 1;
        int right = n - 1;

        while (left < right)
        {
            int sum = nums[left] + nums[right] + nums[i];
            if (sum == 0)
            {
                vector<int> trip = {nums[i], nums[left], nums[right]};
                uniqueTriplets.insert(trip);
                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1])
                    left++;
            }
            else if (sum < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }
}

// Time Complexity :- O(n^2 + n logn)

