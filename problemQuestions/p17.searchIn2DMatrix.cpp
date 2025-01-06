// Search in a 2D matrix
// Given a 2D matrix of size n x m and an integer k. All rows and columns of the 2D matrix are sorted in a non-decreaing order.
// Your task is to search for the integer k in the matrix and return the true if it is present in the matrix. If the element is not present in the matrix then return false.
// The matrix is given in the form of a 2D array.

#include <iostream>
#include <vector>
using namespace std;

bool searchInMatrix(vector<vector<int>> &matrix, int k)
{
    int m = matrix.size(), n = matrix[0].size();
    int startRow = 0, endRow = m - 1;

    while (startRow <= endRow)
    {
        int midRow = startRow + (endRow - startRow) / 2;
        if (k >= matrix[midRow][0] && k <= matrix[midRow][n - 1])
        {
            int startCol = 0, endCol = n - 1;
            while (startCol <= endCol)
            {
                int midCol = startCol + (endCol - startCol) / 2;
                if (matrix[midRow][midCol] == k)
                    return true;
                else if (matrix[midRow][midCol] < k)
                    startCol = midCol + 1;
                else
                    endCol = midCol - 1;
            }
            return false;
        }
        else if (k < matrix[midRow][0])
            endRow = midRow - 1;
        else
            startRow = midRow + 1;
    }

    return false;
}

// Time Complexity :- O(log(n) + log(m))
// Space Complexity :- O(1)

// Given a matrix of type 
// 1   4   7   11  15
// 2   5   8   12  19
// 3   6   9   16  22
// 10  13  14  17  24
// 18  21  23  26  30
// and k = 5

bool searchMatrix(vector<vector<int>> &matrix, int k)
{
    int m = matrix.size(), n = matrix[0].size();
    int r = 0, c = n - 1;

    while(r < m && c >= 0){
        if (matrix[r][c] == k)
            return true;
        else if (matrix[r][c] < k)
            r++;
        else
            c--;
    }

    return false;
}

// Time Complexity :- O(n + m)