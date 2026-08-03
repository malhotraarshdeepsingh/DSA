// This is a C++ implementation of a solution to search for a target value in a 2D matrix. The matrix has the properties that each row is sorted in ascending order from left to right, and each column is sorted in ascending order from top to bottom.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int s = 0;
        int e = m * n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            int row = mid / n;
            int col = mid % n;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                s = mid + 1;
            else
                e = mid - 1;
        }

        return false;
    }
};

// Time Complexity: O(log(m * n)) = O(log m + log n)
// Space Complexity: O(1)