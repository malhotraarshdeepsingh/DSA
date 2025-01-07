#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

set<vector<int>> s;

void getAllCombinations(vector<int> &arr, int target, int index, vector<int> &currentCombination, vector<vector<int>> &result)
{
    if (target < 0 || index == arr.size())
        return;

    if (target == 0)
    {
        if (s.find(currentCombination) == s.end())
        {
            result.push_back(currentCombination);
            s.insert(currentCombination);
            return;
        }
    }

    currentCombination.push_back(arr[index]);
    // single
    getAllCombinations(arr, target - arr[index], index + 1, currentCombination, result);
    // multiple
    getAllCombinations(arr, target - arr[index], index, currentCombination, result);
    currentCombination.pop_back();

    // exclusion
    getAllCombinations(arr, target, index + 1, currentCombination, result);
}

vector<vector<int>> CombinationsSum(vector<int> &arr, int target)
{
    vector<vector<int>> result;
    vector<int> currentCombination;

    getAllCombinations(arr, target, 0, currentCombination, result);

    return result;
}
