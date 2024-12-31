// Search in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

int search(vector<int> &nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }

        if (nums[left] <= nums[mid])
        {
            if (nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if (nums[mid] < target && target <= nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    vector<int> numbers = {60, 70, 10, 20, 40, 50};
    int target = 0;
    int target_num = 60;

    int result = search(nums, target);
    int result2 = search(numbers, target_num);

    if (result == -1 || result2 == -1)
    {
        cout << "Element not found\n";
        return 0;
    }

    cout << "Element found at index: " << result << "\n";
    cout << "Element found at index: " << result2 << "\n";

    return 0;
}