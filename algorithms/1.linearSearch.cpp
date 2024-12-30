#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;  // Return -1 if the element is not found
}

int main() {
    int arr[] = {5, 3, 8, 4, 2, 7, 6};
    int target = 4;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}

// Time complexity: O(n)
// Space complexity: O(1)
// where n is the number of elements in the array
