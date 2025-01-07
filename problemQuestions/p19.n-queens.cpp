#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<string> &board, int row, int col, int n)
{
    for (int i = 0; i < n; i++)
        if (board[row][i] == 'Q')
            return false;

    for (int i = 0; i < n; i++)
        if (board[i][col] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q')
            return false;

    for (int i = row, j = col; i >= 0 && j < n; i--, j++)
        if (board[i][j] == 'Q')
            return false;

    return true;

    // Time Complexity :- O(n)
}

void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &result)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (isSafe(board, row, i, n))
        {
            board[row][i] = 'Q';                // Place Queen
            nQueens(board, row + 1, n, result); // Recur for next row
            board[row][i] = '.';                // Backtrack
        }
    }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));

    nQueens(board, 0, n, result);
    // Time Complexity :- O(n^2)

    return result;
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    vector<vector<string>> result = solveNQueens(n);

    // Display all the solutions
    cout << "Total Solutions: " << result.size() << endl;
    for (const auto &solution : result)
    {
        for (const auto &row : solution)
        {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
