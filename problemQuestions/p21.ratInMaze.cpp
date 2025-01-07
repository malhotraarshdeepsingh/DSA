#include <iostream>
#include <vector>
#include <string>

using namespace std;

void helper(vector<vector<int>> &mat, int r, int c, string path, vector<string> &result) {
    int m = mat.size();

    // Out of bounds or blocked cell
    if (r < 0 || r >= m || c < 0 || c >= m || mat[r][c] != 1) {
        return;
    }

    // Destination reached
    if (r == m - 1 && c == m - 1) {
        result.push_back(path);
        return;
    }

    // visited[r][c] = true;
    mat[r][c] = -1; // Mark as visited

    // Explore in all directions
    helper(mat, r + 1, c, path + 'D', result); // Down
    helper(mat, r, c + 1, path + 'R', result); // Right
    helper(mat, r - 1, c, path + 'U', result); // Up
    helper(mat, r, c - 1, path + 'L', result); // Left

    mat[r][c] = 1; // Unmark during backtracking
    // visited[r][c] = false;
}

vector<string> findPath(vector<vector<int>> &maze) {
    vector<string> result;
    // int n = maze.size();
    // vector<vector<bool>> visited(n, vector<bool>(n, false)); // Initialize visited matrix

    // Edge case: start or end blocked
    if (maze.empty() || maze[0][0] == 0 || maze[maze.size() - 1][maze.size() - 1] == 0) {
        return result;
    }

    helper(maze, 0, 0, "", result);
    return result;
}

int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}};

    vector<string> paths = findPath(maze);

    cout << "Paths from top-left to bottom-right:" << endl;
    if (paths.empty()) {
        cout << "No paths found!" << endl;
    }
    for (string path : paths) {
        cout << path << endl;
    }

    return 0;
}
