#include <iostream>
#include <vector>
using namespace std;

void nextPermutation(vector <int> &A)
{
    // inbuilt function
    // next_permutation(A.begin(), A.end());

    // find pivot
    int pivot = -1, n = A.size();
    for (int i = n - 1; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            pivot = i;
            break;
        }
    }

    if (pivot == -1)
    {
        reverse(A.begin(), A.end()); // in place changes
        return;
    }

    // find next greater element
    for (int i = n - 1; i > pivot; i--)
    {
        if (A[i] > A[pivot])
        {
            swap(A[i], A[pivot]);
            break;
        }
    }

    // reverse the elements after pivot
    // reverse(A.begin() + pivot + 1, A.end());
    int i = pivot + 1, j = n - 1;
    while (i < j)
    {
        swap(A[i], A[j]);
        i++;
        j--;
    }
}