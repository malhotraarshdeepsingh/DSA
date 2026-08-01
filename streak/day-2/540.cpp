// This is a C++ implementation of a solution to find the single element that appears only once in a sorted array using binary search.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;

            if (mid == 0 && nums[0] != nums[1])
                return nums[0];
            if (mid == n - 1 && nums[n - 1] != nums[n - 2])
                return nums[n - 1];

            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            if (mid % 2 == 0)
            {
                if (nums[mid] == nums[mid + 1])
                    left = mid + 2;
                else
                    right = mid;
            }
            else
            {
                if (nums[mid] == nums[mid - 1])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return nums[left];
    }
};

// Time Complexity: O(log n)
// Space Complexity: O(1)