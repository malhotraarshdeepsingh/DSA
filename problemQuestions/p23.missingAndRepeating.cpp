#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector <int> findMissingAndRepeating(vector <vector <int>> &arr)
{
    int n = arr.size();
    vector <int> result;
    unordered_set<int> s;
    int a, b;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
            if (s.find(arr[i][j]) != s.end()){
                a = arr[i][j];
                result.push_back(a);
                break;
            }

            s.insert(arr[i][j]);
        }
    }

    int missing = sum - (n * (n + 1)) / 2;
    int b = missing + a;
    result.push_back(b);

    return result;
}