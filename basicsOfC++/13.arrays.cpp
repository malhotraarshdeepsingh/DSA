#include <iostream>
#include <climits>
using namespace std;

void reverseArray(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int max = arr[0], min = INT_MAX, secondMin = INT_MAX;
    // INT_MAX is a constant in C and C++ that represents the maximum value that an int (integer) type can hold on a given platform.
    // secondMin is initialized with INT_MAX to ensure that it gets updated with the actual second minimum value.

    // loop to find max, min and second minimum values
    for (int i = 0; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            secondMin = min;
            min = arr[i];
        } else if (arr[i] < secondMin && arr[i] != min) {
            secondMin = arr[i];
        }
    }

    cout << "Maximum value: " << max << endl;
    cout << "Minimum value: " << min << endl;
    cout << "Second minimum value: " << secondMin << endl;

    int size = sizeof(arr) / sizeof(arr[0]);
    reverseArray(arr, size);
    cout << "Reversed array: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}