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

    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        int fresh = 0;
        list<pair<int, int>> q;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push_back({i, j});
                }
                else if (grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        int time = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++)
            {
                auto node = q.front();
                q.pop_front();

                for (int k = 0; k < 4; k++)
                {
                    int x = node.first + dx[k];
                    int y = node.second + dy[k];

                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == 1)
                    {
                        grid[x][y] = 2;
                        fresh--;
                        q.push_back({x, y});
                        flag = true;
                    }
                }
            }

            if (flag)
            {
                time++;
            }
        }

        if (fresh == 0)
        {
            return time;
        }
        return -1;
    }
};

int main()
{
    Graph g(5);
    vector<vector<int>> grid = {
        {2, 1, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 1, 1}};
    cout << g.orangesRotting(grid) << endl;

    return 0;
}
