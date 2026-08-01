// This is a C++ implementation of a solution to search for a target value in a rotated sorted array using binary search.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
                return mid;

            if (nums[s] <= nums[mid]) {
                if (target >= nums[s] && target < nums[mid])
                    e = mid - 1;
                else
                    s = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }

        return -1;
    }
};

// Time Complexity: O(log n)
// Space Complexity: O(1)