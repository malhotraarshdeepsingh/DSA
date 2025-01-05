#include <iostream>
#include <string>
#include <vector>
using namespace std;

int compress (vector<char> &chars)
{
    int idx = 0, n = chars.size();

    for (int i = 0; i < n; i++)
    {
        char ch = chars[i];
        int count = 0;
        
        while (i < n && chars[i] == ch)
        {
            count++;
            i++;
        }

        if (count == 1)
        {
            chars[idx++] = ch;
        }
        
        chars[idx++] = ch;
        string str = to_string(count);
        for (char dig : str)
        {
            chars[idx++] = dig;
        }

        i--;
    }

    chars.resize(idx);
    return idx;
}

// Time Complexity :- O(n)