#include <iostream>
using namespace std;

// Vector Header File
#include <vector>

int main() {
    // Vectos are array like data types in C++ which deffernce from array because they are dynamic in size

    // Method 1
    vector<int> num1={1,2,3,4,5};

    cout << "Vector size: " << num1.size() << endl;
    cout << "First element: " << num1[0] << endl;
    cout << "Last element: " << num1[num1.size()-1] << endl;

    // Method 2
    vector<int> num2(5, 10); // 5 elements with value 10

    cout << "Vector size: " << num2.size() << endl;
    cout << "First element: " << num2[0] << endl;
    cout << "Last element: " << num2[num2.size()-1] << endl;

    // Special loop for Vectors - for each loop iteration
    for (int i : num1)
    {
        cout << i << " ";
    }

    // Vector Functions 
    // size - returns the number of elements in the vector
    // push_back - adds an element to the end of the vector
    // pop_back - removes the last element from the vector
    // front - returns the first element of the vector
    // back - returns the last element of the vector
    // at - returns the value at the particular index

    // Examples

    vector<int> num3;
    cout << "\nVector size: " << num3.size() << endl;

    num3.push_back(10);
    num3.push_back(20);
    num3.push_back(30);

    cout << "\nVector size after push back: " << num3.size() << endl;
    for (int i : num3)
    {
        cout << i << " ";
    }

    num3.pop_back();
    cout << "\nVector size after pop back: " << num3.size() << endl;
    for (int i : num3)
    {
        cout << i << " ";
    }

    cout << "\nFirst element: " << num3.front() << endl;
    cout << "\nLast element: " << num3.back() << endl;
    cout << "\nElement at index 1: " << num3.at(1) << endl;

    return 0;
}