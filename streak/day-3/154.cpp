// This is a C++ implementation of a solution to find the minimum element in a rotated sorted array using binary search.

class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
                continue;
            }

            if (nums[mid] > nums[e]) {
                s = mid + 1;
            } else {
                e = mid;
            }
        }

        return nums[s];
    }
};

// Time Complexity: O(log n) in average case, O(n) in worst case
// Space Complexity: O(1)