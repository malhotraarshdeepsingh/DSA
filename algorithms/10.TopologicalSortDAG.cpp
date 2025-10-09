// DAG -> Directed Acyclic Graph

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

    vector<int> topologicalSort()
    {
        vector<int> indegree(v, 0);
        for (int i = 0; i < v; i++)
        {
            for (auto nbr : l[i])
            {
                indegree[nbr]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < v; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto nbr : l[node])
            {
                indegree[nbr]--;
                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }

        return ans;
    }
    // Time complexity: O(V + E)
    // Space complexity: O(V)
};

int main()
{
    Graph g(6);
    
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    vector<int> ans = g.topologicalSort();
    for (auto node : ans)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}