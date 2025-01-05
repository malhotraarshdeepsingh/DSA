#include <iostream>
#include <climits>
#include <vector>
using namespace std;

pair<int, int> linearSearch(int arr[][3], int rows, int cols, int key)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] == key)
            {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

int maximunColSum(int arr[][3], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < cols; i++)
    {
        int sum = 0;
        for (int j = 0; j < rows; j++)
        {
            sum += arr[j][i];
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int maximunRowSum(int arr[][3], int rows, int cols)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < rows; i++)
    {
        int sum = 0;
        for (int j = 0; j < cols; j++)
        {
            sum += arr[i][j];
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int diagnalSum(int arr[][3], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || j == n - i - 1)
            {
                sum += arr[i][j];
            }
        }
    }

    return sum;
}

int main()
{
    int matrix[4][3];

    // Initialize the matrix with values
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matrix[i][j] = i + j;
        }
    }

    // Print the matrix
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    vector<vector<int>> matrix2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    return 0;
}