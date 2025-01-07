#include <iostream>
#include <vector>

using namespace std;

void getPermutations(vector<int> &arr, int index, vector<vector<int>> &result)
{
    if (index == arr.size())
    {
        result.push_back({arr});
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        getPermutations(arr, index + 1, result);
        swap(arr[index], arr[i]);
    }
}

vector<vector<int>> permute(vector<int> &arr)
{
    vector<vector<int>> result;
    getPermutations(arr, 0, result);
    return result;
}

// Time Complexity :- O(n * n!)