// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

#include <iostream>
#include <vector>
using namespace std;

int countNiceSubarrays(vector<int> &nums, int k)
{
    int left = 0, right = 0, oddCount = 0, result = 0, prefixEven = 0;

    while (right < nums.size())
    {
        if (nums[right] % 2 == 1)
        {
            oddCount++;
            prefixEven = 0;
        }

        while (oddCount > k)
        {
            if (nums[left] % 2 == 1)
            {
                oddCount--;
            }
            left++;
        }

        while (left < nums.size() && nums[left] % 2 == 0)
        {
            prefixEven++;
            left++;
        }

        if (oddCount == k)
        {
            result += (prefixEven + 1);
        }

        right++;
    }

    return result;
}