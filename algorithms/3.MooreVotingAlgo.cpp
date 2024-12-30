#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to find pair in sorted array whose sum is equal to given number
vector<int> pairSum(vector<int> nums, vector<int> target)
{
    vector<int> ans;
    int n = nums.size();

    int i = 0, j = n - 1;
    while (i < j)
    {
        int pairSum = nums[i] + nums[j];
        if (pairSum == target[0])
        {
            ans.push_back(nums[i]);
            ans.push_back(nums[j]);
            return ans;
        }
        else if (pairSum < target[0])
            i++;
        else
            j--;
    }

    return ans;
}

// Function to find the majority element in an array --- by brute force method
// Time Complexity: O(n^2)
int majorityElementBruteForce(vector<int> nums)
{
    for (int val : nums)
    {
        int freq = 0;

        for (int num : nums)
        {
            if (num == val)
                freq++;
        }

        if (freq > nums.size() / 2)
            return val;
    }
}

// Function to find the majority element in an array --- by sorting the array
int majorityElement(vector<int> nums)
{
    int n = nums.size();

    // sort the array
    sort(nums.begin(), nums.end());

    // freq count
    int freq = 1, ans = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            freq++;
        }
        else
        {
            freq = 1;
            ans = nums[i];
        }

        if (freq > n / 2)
            return ans;
    }
}

// Function to find the majority element in an array --- by Moore's Voting Algorithm
int majorityElementMoore(vector<int> nums)
{
    int majority = nums[0], count = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (count == 0)
        {
            majority = nums[i];
        }

        if (nums[i] == majority)
            count++;
        else
            count--;
    }

    int freq = 0;
    for (int val : nums)
    {
        if (val == majority)
            freq++;
    }

    if (freq > nums.size() / 2)
        return majority;
    else
        return -1; // majority element not found
}

int main()
{
    vector<int> nums = {1, 4, 6, 10};
    vector<int> target = {16};

    vector<int> result = pairSum(nums, target);
    cout << "Pair found: (" << result[0] << ", " << result[1] << ")" << endl;

    return 0;
}