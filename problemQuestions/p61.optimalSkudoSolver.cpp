#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

bool isValid(vector<vector<char>> &board, int row, int col, char digit)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == digit || board[i][col] == digit ||
            board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == digit)
        {
            return false;
        }
    }
    return true;
}

pair<int, int> find(vector<vector<char>> &board)
{
    int minOptions = 10; // More than the max possible (1-9)
    pair<int, int> bestCell = {-1, -1};

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (board[row][col] == '.')
            {
                int options = 0;
                for (char digit = '1'; digit <= '9'; digit++)
                {
                    if (isValid(board, row, col, digit))
                    {
                        options++;
                    }
                }
                if (options < minOptions)
                {
                    minOptions = options;
                    bestCell = {row, col};
                }
            }
        }
    }
    return bestCell;
}

bool solve(vector<vector<char>> &board)
{
    pair<int, int> cell = find(board);
    int row = cell.first, col = cell.second;

    if (row == -1 && col == -1)
    {
        return true; // Solved
    }

    for (char digit = '1'; digit <= '9'; digit++)
    {
        if (isValid(board, row, col, digit))
        {
            board[row][col] = digit;

            if (solve(board))
                return true;

            board[row][col] = '.'; // Backtrack
        }
    }

    return false;
}

void printBoard(const vector<vector<char>> &board)
{
    for (const auto &row : board)
    {
        for (char cell : row)
            cout << cell << " ";
        cout << "\n";
    }
}

// Time Complexity: O(9^(n))
// Space Complexity: O(1)