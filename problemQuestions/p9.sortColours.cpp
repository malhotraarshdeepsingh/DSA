// Given an array nums with n objects coloured red, white and blue, sort them in-place so that objects of the same colour are adjacent, with the colours in the order red, white and blue.
// We will use integers 0, 1, and 2 to represent the colour red, white, and blue respectively.
// You must solve this problem without using the library's sort function.

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortColorsCount(vector<int>& nums) {
    int n = nums.size();
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;
    
    // Count the number of elements of each colour
    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            count0++;
        } else if (nums[i] == 1) {
            count1++;
        } else {
            count2++;
        }
    }

    // Overwrite the array with the colours
    for (int i = 0; i < count0; i++) {
        nums[i] = 0;
    }
    for (int i = count0; i < count0 + count1; i++) {
        nums[i] = 1;
    }
    for (int i = count0 + count1; i < n; i++) {
        nums[i] = 2;
    }

    return nums;
}

// Dutch National Flag Algorithm
void sortColors(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    
    while (mid <= high) {
        switch (nums[mid]) {
            case 0:
                swap(nums[low++], nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(nums[mid], nums[high--]);
                break;
        }
    }
}

int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> result = sortColorsCount(nums);
    // Time Complexity - O(n)

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}