#include <iostream>
#include <vector>
#include <list>
#include <queue>
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

    void bfs()
    {
        queue<int> q;
        vector<bool> visited(v, false);

        q.push(0);
        visited[0] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            cout << u << ",";

            for (auto v : l[u])
            {
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }

        cout << endl;
    }

    void dfsHelper(int u, vector<bool> &visited)
    {
        cout << u << ",";
        visited[u] = true;

        for (auto v : l[u])
        {
            if (!visited[v])
            {
                dfsHelper(v, visited);
            }
        }
    }

    void dfs()
    {
        vector<bool> visited(v, false);
        dfsHelper(0, visited);
    }

    bool cycleDetectionHelper(int u, int par, vector<bool> &visited)
    {
        cout << u << ",";
        visited[u] = true;
        list<int> neighbors = l[u];

        for (auto v : neighbors)
        {
            if (!visited[v])
            {
                if (cycleDetectionHelper(v, u, visited))
                    return true;
            } else if (v != par)
            {
                cout << "Cycle detected at node: " << v << endl;
                return true;
            }
        }

        return false;
    }

    bool cycleDetection()
    {
        vector<bool> visited(v, false);
        
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (cycleDetectionHelper(i, -1, visited))
                {
                    cout << "Cycle found in the graph." << endl;
                    return true;
                }
            }
        }

        cout << "No cycle found in the graph." << endl;
        return false;

        // Time Complexity: O(V + E)
        // Space Complexity: O(V)
    }
};

int main()
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.printAdjList();

    g.bfs();
    g.dfs();

    g.cycleDetection(); 

    return 0;
}