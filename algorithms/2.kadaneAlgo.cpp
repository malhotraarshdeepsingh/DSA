#include <iostream>
#include <climits> // For INT_MIN
#include <algorithm> // For max function
#include <vector>
using namespace std;

int maxSubArray(vector<int> &nums){
    int currSum = 0, maxSum = INT_MIN;

    for (int val : nums) {
        currSum += val;
        maxSum = max(currSum, maxSum);
        
        if (currSum < 0) {
            currSum = 0;
        }
    }

    return maxSum;
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num = sizeof(arr) / sizeof(arr[0]);

    // loop to find all subarrays of an array
    
    for (int start = 0; start < num; start++) {
        for (int end = start; end < num; end++) {
            for (int i = start; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }


    // Brute force approach to find maximum subarry sum of an array

    int maxSum = INT_MIN;

    for (int start = 0; start < num; start++) {
        int currentSum = 0;
        for (int end = start; end < num; end++) {
            currentSum += arr[end];
            maxSum = max(currentSum, maxSum);
        }
    }

    cout << "Maximum subarray sum: " << maxSum << endl;

    // Time Complexity: O(n^3)
    

    // Kadane's algorithm to find maximum subarray sum of an array

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max_Sum = maxSubArray(nums);
    cout << "Maximum subarray sum using Kadane's algorithm: " << max_Sum << endl;

    // Time Complexity: O(n)


    return 0;
}