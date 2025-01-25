#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    unordered_map<char, int> charIndexMap; 
    int maxLength = 0;                     
    int start = 0;                         

    for (int end = 0; end < s.size(); ++end)
    {
        char currentChar = s[end];

        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start)
        {
            start = charIndexMap[currentChar] + 1;
        }

        charIndexMap[currentChar] = end;

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}