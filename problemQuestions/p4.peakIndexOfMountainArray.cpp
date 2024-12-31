#include <iostream>
#include <vector>
using namespace std;

int peakIndexOfMountainArray(vector<int> &A)
{
    int left = 0;
    int right = A.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (A[mid - 1] < A[mid] && A[mid] > A[mid + 1])
        {
            return mid;
        }
        else if (A[mid-1] < A[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
}

int main()
{
    vector<int> nums = {0, 1, 0};
    vector<int> numbers = {0, 2, 1, 0};
    vector<int> num = {0, 10, 5, 2};
    vector<int> number = {3, 4, 5, 1};
    
    int result1 = peakIndexOfMountainArray(nums);
    int result2 = peakIndexOfMountainArray(numbers);
    int result3 = peakIndexOfMountainArray(num);
    int result4 = peakIndexOfMountainArray(number);

    cout << "Peak index of mountain array: " << result1 << "\n";
    cout << "Peak index of mountain array: " << result2 << "\n";
    cout << "Peak index of mountain array: " << result3 << "\n";
    cout << "Peak index of mountain array: " << result4 << "\n";

    return 0;
}