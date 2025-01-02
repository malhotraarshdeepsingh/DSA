#include <iostream>
#include <vector>

using namespace std;

int main()
{
    pair<string, int> p = {"newyear", 2025};

    // pair of pair
    pair<string, pair<int, char>> q = {"newyear", {2026, 'A'}};

    cout << p.first << " " << p.second << endl;
    cout << q.first << " " << q.second.first << " " << q.second.second << endl;

    // vector of pairs
    vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};
    for (pair<int, int> val : v) // or use auto key
    {
        cout << val.first << " " << val.second << endl;
    }

    v.push_back({1, 1});
    v.emplace_back(1, 1); // same as push_back, but converts individual values to objects

    return 0;
}