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

    bool cycleHelper(int node, vector<bool> &visited, vector<bool> &stack)
    {
        visited[node] = true;
        stack[node] = true;

        for (auto nbr : l[node])
        {
            if (stack[nbr] == true)
            {
                return true;
            }
            else if (!visited[nbr])
            {
                bool cycleDetected = cycleHelper(nbr, visited, stack);
                if (cycleDetected)
                {
                    return true;
                }
            }
        }

        stack[node] = false;
        return false;
    }

    bool containsCycle()
    {
        vector<bool> visited(v, false);
        vector<bool> stack(v, false);

        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                bool cycleDetected = cycleHelper(i, visited, stack);
                if (cycleDetected)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Graph g(4);

    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 0);

    if (g.containsCycle())
    {
        cout << "Graph contains cycle" << endl;
    }
    else
    {
        cout << "Graph doesn't contain cycle" << endl;
    }

    // Time complexity: O(V + E)
    // Space complexity: O(V)

    return 0;
}