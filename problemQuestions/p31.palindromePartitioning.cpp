#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string s)
{
    string str = s;

    reverse(str.begin(), str.end());

    return str == s;
}

void getAllParts(string s, vector<string> &partitions, vector<vector<string>> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(partitions);
        return;
    }

    for (int i = 0; i < s.size(); i++)
    {
        string part = s.substr(0, i + 1);

        if (isPalindrome(part))
        {
            partitions.push_back(part);
            getAllParts(s.substr(i + 1), partitions, ans);
            partitions.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<string> partitions;
    vector<vector<string>> ans;

    getAllParts(s, partitions, ans);

    return ans;
}