#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector <int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> result;
    deque<int> dq;

    for (int i = 0; i < nums.size(); i++) {
        // Remove elements not in the current window
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // Remove elements smaller than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // The front of the deque is the largest element for the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

// Time Complexity: O(n)
// Space Complexity: O(k)