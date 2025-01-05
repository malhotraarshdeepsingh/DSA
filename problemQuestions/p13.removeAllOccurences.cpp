// remove all occurances of a substring

#include <iostream>
#include <string>
using namespace std;

string removeSubstring(string str, string toRemove)
{
    while (str.length() > 0 && str.find(toRemove) < str.length())
    {
        str.erase(str.find(toRemove), toRemove.length());
    }
    return str;
}

int main()
{
    string str = "hello world hello";
    string toRemove = "hello";

    string newStr = removeSubstring(str, toRemove);
    cout << newStr << endl;

    return 0;
}