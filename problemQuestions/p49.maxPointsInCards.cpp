// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
// Your score is the sum of the points of the cards you have taken.
// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int totalSum = 0;

    for (int points : cardPoints) {
        totalSum += points;
    }

    if (k == n) return totalSum;

    int windowSize = n - k;
    int minSubarraySum = 0, currentSum = 0;

    for (int i = 0; i < windowSize; i++) {
        currentSum += cardPoints[i];
    }

    minSubarraySum = currentSum;

    for (int i = windowSize; i < n; i++) {
        currentSum += cardPoints[i] - cardPoints[i - windowSize];
        minSubarraySum = min(minSubarraySum, currentSum);
    }

    return totalSum - minSubarraySum;
}