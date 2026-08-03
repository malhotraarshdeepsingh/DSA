// This is a C++ implementation of a solution to search for a target value in a 2D matrix. The matrix has the properties that each row is sorted in ascending order from left to right, and each column is sorted in ascending order from top to bottom.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowIndex = 0;
        int colIndex = col - 1;

        while (rowIndex < row && colIndex >= 0){
            int element = matrix[rowIndex][colIndex];

            if (element == target) {
                return 1;
            }

            if (element < target) {
                rowIndex++;
            } else {
                colIndex--;
            }
        }
        return 0;
    }
};

// Time Complexity: O(m + n), where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1), as we are using a constant amount of space.