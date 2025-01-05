// Given two strings, return true if s2 contains a permutation of s1, or false otherwise.
#include <iostream>
#include <string>

using namespace std;

bool isFreqSame(int freq1[], int freq2[])
{
    for (int i = 0; i < 26; i++)
    {
        if (freq1[i] != freq2[i])
        {
            return false;
        }
    }

    return true;
}

bool isPermutation(string s1, string s2)
{

    int freq[26] = {0};

    // Count the frequency of characters in s1
    for (char c : s1)
    {
        freq[c - 'a']++;
    }

    int windSize = s1.length();

    for (int i = 0; i < s2.length(); i++)
    {
        int windIdx = 0, idx = i;
        int windFreq[26] = {0};

        // Slide the window to find a permutation of s1 in s2
        while (windIdx < windSize && idx < s2.length())
        {
            windFreq[s2[idx] - 'a']++;
            windIdx++;
            idx++;
        }

        if (isFreqSame(freq, windFreq))
        {
            return true;
        }
    }

    return false;
}