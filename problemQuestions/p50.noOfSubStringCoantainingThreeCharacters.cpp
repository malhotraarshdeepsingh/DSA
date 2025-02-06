// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

#include <iostream>
#include <vector>
using namespace std;

int countSubstrings(string s) {
    int n = s.length();
    vector<int> count(3, 0);  
    int left = 0, result = 0;

    for (int right = 0; right < n; right++) {
        count[s[right] - 'a']++;

        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            result += (n - right); 
            count[s[left] - 'a']--;
            left++;
        }
    }

    return result;
}