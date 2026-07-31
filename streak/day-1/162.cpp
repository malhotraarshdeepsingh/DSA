// This is a C++ implementation of a solution to find a peak element in an array using binary search.

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0, e = nums.size() -1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[mid + 1])
                s = mid + 1;
            else
                e = mid;
        }

        return s;
    }
};

// Time Complexity: O(log n)
// Space Complexity: O(1)