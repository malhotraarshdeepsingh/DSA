#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n; j++)
        {
            long long sum = 0;
            int left = j + 1;
            int right = n - 1;

            while (left < right)
            {
                sum = (long long)(nums[i] + nums[j] + nums[left] + nums[right]);
            }

            if (sum == target)
            {
                vector<int> quad = {nums[i], nums[j], nums[left], nums[right]};
                result.push_back(quad);

                while (left < right && nums[left] == nums[left-1])
                    left++;
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }

            j++; // Move to the next element

            while (j < n && nums[j] == nums[j + 1])
                j++;
        }
    }
}

// Time Complexity :- O(n^3 + nlogn)