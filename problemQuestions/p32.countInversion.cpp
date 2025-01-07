#include <iostream>
#include <vector>
using namespace std;

int merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    
    int invCount = 0;

    vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
            invCount += (n1 - i); // Count inversions
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    return invCount;
}

int mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        int leftInvCount = mergeSort(arr, left, mid);
        int rightInvCount = mergeSort(arr, mid + 1, right);

        int invCount = merge(arr, left, mid, right);

        return leftInvCount + rightInvCount + invCount;
    }

    return 0; // No inversions in a single element array
}

int main() {
    // vector<int> arr = {6, 3, 5, 2, 7};
    vector<int> arr = {1, 3, 5, 10, 2, 6, 8, 9};

    int ans = mergeSort(arr, 0, arr.size() - 1);
    cout << "Number of inversions: " << ans << endl;

    return 0;
}

// Time Complexity: O(nlogn)
// Space Complexity: O(n)