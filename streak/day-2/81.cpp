// This is a C++ implementation of a solution to search for a target value in a rotated sorted array using binary search.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size() - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
                return true;

            if (nums[s] == nums[mid] && nums[mid] == nums[e]) {
                s++;
                e--;
                continue;
            }

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

        return false;

    }
};

// Time Complexity: O(log n) in average case, O(n) in worst case
// Space Complexity: O(1)