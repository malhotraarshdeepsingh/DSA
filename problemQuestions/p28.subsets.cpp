#include <iostream>
#include <vector>

using namespace std;

void printSubsets(vector<int> &arr, int index, vector<int> &currentSubset)
{
    if (index == arr.size())
    {
        for (int num : currentSubset)
        {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // Include the current element
    currentSubset.push_back(arr[index]);
    printSubsets(arr, index + 1, currentSubset);

    currentSubset.pop_back();

    // Skip duplicates
    int idx = index + 1;
    while(idx < currentSubset.size() && currentSubset[idx] == currentSubset[index])
        idx++;

    // Exclude the current element
    printSubsets(arr, idx, currentSubset);
}

// Time Complexity :- O(n * 2^n)