#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]); 
        }
    }
    swap(arr[i + 1], arr[high]); 
    return i + 1;              
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printVector(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};

    cout << "Unsorted vector: ";
    printVector(arr);

    quickSort(arr, 0, arr.size() - 1);

    cout << "Sorted vector: ";
    printVector(arr);

    return 0;
}

// Time Complexity: O(n log n) on average, O(n^2) in the worst case (when the array is already sorted or reverse sorted or pivot is smallest or largest element)
// Space Complexity: O(log n) for the recursive stack space