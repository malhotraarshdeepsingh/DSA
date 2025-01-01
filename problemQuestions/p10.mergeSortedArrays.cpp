#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int>& v1, vector <int>& v2, int n, int m)
{
    int idx = m + n - 1, i = m - 1, j = n - 1;

    while (i >= 0 && j >= 0)
    {
        if (v1[i] > v2[j])
        {
            v1[idx--] = v1[i--];
        }
        else
        {
            v1[idx--] = v2[j--];
        }
    }

    while (j >= 0)
    {
        v1[idx--] = v2[j--];
    }

    // Time Complexity - O(n + m) 
}