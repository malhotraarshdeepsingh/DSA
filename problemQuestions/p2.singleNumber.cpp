// Given a non-empty array of integers, every element appears twice except for one. Find that single one.

#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums) {
    int result = 0;

    for (int num : nums) {
        result ^= num;
    }
    // bitwise XOR will remove all duplicate values as there binary representation will be same and we will be left with the single number

    return result;
}

int main() {
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << singleNumber(nums) << endl;

    return 0;
}