#include <iostream>
using namespace std;

// Binary search function for ascending sorted array
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        // optimized binary search
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

// Binary search function with recursion
int binarySearchRecursive(int arr[], int left, int right, int target) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            return binarySearchRecursive(arr, mid + 1, right, target);
        } else {
            return binarySearchRecursive(arr, left, mid - 1, target);
        }
    }

    return -1;
}

int main() {
    // Binary search is an efficient searching algorithm used to find the position of a target element within a sorted array. It works by repeatedly dividing the search interval in half, effectively reducing the search space.

    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target = 10;

    int result = binarySearch(arr, n, target);
    
    if (result == -1) {
        cout << "Element not found\n";
        return 0;
    }

    cout << "Element found at index: " << result << "\n";

    return 0;
}