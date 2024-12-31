// There are N boooks, each ith has A[i] number of pages.
// You have to allocate books to M students so that maximum number of pages alloted to a student is minimum.
// Rules
// 1. Each student gets atleast one book.
// 2. Each book will be alloted to exactly one student.
// 3. Allotment should be in contiguous order.
// Calculate and return that minimum posiible number.
// Return -1 if a valid number is not possible.

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

bool isValid(vector<int> &books, int students, int maxPages)
{
    int currentSum = 0;
    int requiredStudents = 1;

    for (int pages : books)
    {
        if (currentSum + pages > maxPages)
        {
            requiredStudents++;
            currentSum = pages;

            if (requiredStudents > students)
                return false;
        }
        else
        {
            currentSum += pages;
        }
    }

    return true;
}

int allocateBooks(vector<int> &books, int students)
{
    int n = books.size();
    if (students > n)
        return -1;

    int low = *max_element(books.begin(), books.end());
    int high = accumulate(books.begin(), books.end(), 0);
    int result = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isValid(books, students, mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return result;
}

int main()
{
    vector<int> books = {12, 34, 67, 90};
    int students = 2;

    int result = allocateBooks(books, students);
    if (result != -1)
        cout << "Minimum possible maximum pages: " << result << endl;
    else
        cout << "Allocation not possible." << endl;

    return 0;
}