#include <iostream>
#include <vector>

using namespace std;

int canComplete(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();
    int totalGas = 0, totalCost = 0;
    int currentGas = 0, startIndex = 0;

    for (int i = 0; i < n; ++i) {
        totalGas += gas[i];
        totalCost += cost[i];
        currentGas += gas[i] - cost[i];

        if (currentGas < 0) {
            startIndex = i + 1;
            currentGas = 0;
        }
    }

    return (totalGas >= totalCost) ? startIndex : -1;
}

// Time Complexity: O(n)
// Space Complexity: O(1)