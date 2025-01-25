#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> removeDuplicates(vector<int> &nums, int start, int end)
{
    set<int> seen;
    vector<int> result;

    for (int i = start; i <= end && i < nums.size(); i++)
    {
        if (seen.find(nums[i]) == seen.end())
        {
            seen.insert(nums[i]);
            result.push_back(nums[i]);
        }
    }
    return result;
}