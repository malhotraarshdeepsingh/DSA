// Given a array of n x n, return the elements of the array in spiral order.

#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{

    int m = matrix.size(), n = matrix[0].size();
    int srow = 0, scol = 0, erow = m - 1, ecol = n - 1;

    vector<int> result;

    while (srow <= erow && scol <= ecol)
    {
        for (int j = scol; j < ecol; j++)
        {
            result.push_back(matrix[srow][j]);
        }

        for (int i = srow + 1; i <= erow; i++)
        {
            result.push_back(matrix[i][ecol]);
        }

        for (int j = ecol - 1; j >= scol; j--)
        {
            if (srow == erow)
                break; // To avoid duplicate elements
            result.push_back(matrix[erow][j]);
        }

        for (int i = erow - 1; i > srow; i--)
        {
            result.push_back(matrix[i][scol]);
        }

        srow++;
        erow--;
        scol++;
        ecol--;
    }

    return result;

}