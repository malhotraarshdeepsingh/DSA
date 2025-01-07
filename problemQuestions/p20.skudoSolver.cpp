#include <iostream>
#include <vector>

using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char digit)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == digit)
            return false;

        if (board[i][col] == digit)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit)
            return false;
    }

    return true;
}

bool helper(vector<vector<char>> &board, int row, int col)
{
    int nextRow = row, nextCol = col + 1;

    if (nextCol == 9)
    {
        nextRow++;
        nextCol = 0;
    }

    if (board[row][col] != '.')
    {
        if (nextRow == 9)
            return true; // base case

        return helper(board, nextRow, nextCol);
    }

    for (char digit = '1'; digit <= '9'; digit++)
    {
        if (isValid(board, row, col, digit))
        {
            board[row][col] = digit;

            // recursive call
            if (helper(board, nextRow, nextCol))
                return true;

            board[row][col] = '.'; // backtracing
        }
    }

    return false;
}

bool solveSkudo(vector<vector<char>> &board)
{
    helper(board, 0, 0);
    // Time Complexity :- O(9^(n^2))
}