// Painter Partition Problem
// Given are N boards of length of each given in the form of array, and M painters, such that each painter takes 1 unit of time to paint 1 unit of board. The problem is to find the minimum time that will be required to paint all the boards such that each painter paints consecutive boards only.

#include <iostream>
#include <vector>
using namespace std;

int isPossible(vector<int> &boards, int boardCount, int painters, int maxTime)
{
    int painterCount = 1, curSum = 0;

    for (int i = 0; i < boardCount; i++)
    {
        curSum += boards[i];

        if (curSum > maxTime)
        {
            painterCount++;
            curSum = boards[i];

            if (painterCount > painters)
                return false;
        }
    }

    return true;
}

int minTimeToPaintBoards(vector<int> &boards, int painters, int boardCount)
{
    int sum, maxVal = 0;

    for (int i = 0; i < boardCount; i++)
    {
        sum += boards[i];
        maxVal = max(maxVal, boards[i]);
    }

    int st = maxVal, end = sum, ans = -1;

    while (st <= end)
    {
        int mid = (st + end) / 2;
        int painterCount = 1, curSum = 0;

        if(isPossible(boards, boardCount, painters, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> boards = {10, 20, 30, 40};
    int painters = 2;
    int boardCount = boards.size();

    cout << minTimeToPaintBoards(boards, painters, boardCount) << endl;

    return 0;
}