#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int numSubArraysWithSum(vector<int> nums, int goal)
{
    int ans, currSum = 0;
    unordered_map<int, int> freq;

    for(int num: nums) {
        currSum += num;

        if (currSum == goal)
            ans++;
        if (freq.find(currSum - goal) != freq.end())
            ans += freq[currSum - goal];

        freq[currSum]++;
    }
    
    return ans;
}