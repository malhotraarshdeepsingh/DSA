// Single element in sorted array

#include <iostream>
using namespace std;

int singleNumber(int arr[], int n)
{
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (mid == 0 && arr[0] != arr[1])
            return arr[0];
        if (mid == n - 1 && arr[n - 1] != arr[n - 2])
            return arr[n - 1];

        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid + 1])
            return arr[mid];

        if (mid % 2 == 0)
        {
            if (arr[mid] == arr[mid + 1])
                left = mid + 2; 
            else
                right = mid;
        }
        else
        {
            if (arr[mid] == arr[mid - 1])
                left = mid + 1; 
            else
                right = mid - 1;
        }
    }

    return arr[left];
}

int main()
{
    int arr[] = {2, 2, 3, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "The single element is: " << singleNumber(arr, n);

    return 0;
}