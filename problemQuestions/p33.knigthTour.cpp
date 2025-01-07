#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isValidMove(int x1, int y1, int x2, int y2, int n) {
    int dx = abs(x1 - x2);
    int dy = abs(y1 - y2);
    return ((dx == 2 && dy == 1) || (dx == 1 && dy == 2)) && x2 >= 0 && y2 >= 0 && x2 < n && y2 < n;
}

bool checkValidGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<pair<int, int>> positions(n * n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            positions[grid[i][j]] = {i, j};
        }
    }

    for (int i = 1; i < n * n; i++) {
        int x1 = positions[i - 1].first, y1 = positions[i - 1].second;
        int x2 = positions[i].first, y2 = positions[i].second;
        if (!isValidMove(x1, y1, x2, y2, n)) {
            return false;
        }
    }

    return true;
}

int main() {
    vector<vector<int>> grid = {
        {0, 17, 10, 3, 22},
        {11, 4, 23, 16, 9},
        {18, 1, 6, 21, 2},
        {5, 12, 19, 8, 15},
        {24, 7, 14, 13, 20}
    };

    if (checkValidGrid(grid)) {
        cout << "The knight tour configuration is valid." << endl;
    } else {
        cout << "The knight tour configuration is not valid." << endl;
    }

    return 0;
}