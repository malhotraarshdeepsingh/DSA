// DFS -> Depth First Search
#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
    int v;
    list<int> *l; // list of address of adjacent nodes

public:
    Graph(int v)
    {
        this->v = v;
        // arr = new int[v];
        l = new list<int>[v];
    }

    void addEdge(int i, int j)
    {
        // undirected graph
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

    void dfsHelper(int u, vector<bool> &visited) {
        cout << u << ",";
        visited[u] = true;

        for (auto v : l[u]) {
            if (!visited[v]) {
                dfsHelper(v, visited);
            }
        }
    }

    void dfs() {
        vector<bool> visited(v, false);
        dfsHelper(0, visited);
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

    return 0;
}