#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{
    int v;
    list<int> *l;

public:
    Graph(int v)
    {
        this->v = v;
        l = new list<int>[v];
    }

    void addEdge(int i, int j)
    {
        l[i].push_back(j);
        l[j].push_back(i);
    }

    void printAdjList()
    {
        for (int i = 0; i < v; i++)
        {
            cout << i << "->";
            for (auto node : l[i])
            {
                cout << node << ",";
            }
            cout << endl;
        }
    }

    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j)
    {
        int n = grid.size();
        int m = grid[0].size();

        // base case
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;
        if (grid[i][j] == '0' || visited[i][j])
            return;

        visited[i][j] = true;

        // explore all 4 directions
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    islands++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return islands;

        // time complexity: O(n*m)
        // space complexity: O(n*m)
    }
};

int main()
{
    Graph g(5);
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};
    cout << g.numIslands(grid) << endl;

    return 0;
}