// Input :- "today is sunday"
// Output :- "sunday is today"
// O(n)

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseWords(string str)
{
    int len = str.length();
    string result = "";

    reverse(str.begin(), str.end());

    for (int i = 0; i < len; i++)
    {
        string word = "";
        while(i < len && str[i] != ' ')
        {
            word += str[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word.length() > 0)
        {
            result += " " + word;
        }
    }

    return result.substr(1);
}