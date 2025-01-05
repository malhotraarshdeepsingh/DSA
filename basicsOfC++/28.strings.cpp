#include <iostream>

// completely optional to import string class as it is already imported in iostream
#include <string>

#include <algorithm> // for reverse functionality

using namespace std;

int main()
{
    // string is c++ is just a array of characters

    // ways to initalize
    char arr[5] = {'a', 'b', 'c', 'd', '\0'}; // '\0' is a used to end the string
    char str[] = "hello";

    // using inbuilt class in stl
    string s = "world";
    // dynamic in nature, so are more efficient and flexible

    cout << str << endl;
    cout << arr << endl;
    cout << s << endl;

    // input a string
    char str2[100];

    cout << "Enter a string: ";

    // ways to input a string
    cin >> str2;                 // gets only first word
    cin.getline(str2, 100);      // gets all characters until newline is encountered
    cin.getline(str2, 100, '$'); // gets all characters until '$' is encountered

    cout << "You entered: " << str2 << endl;

    string str1 = "Hello";
    string str3 = "World";
    string str4 = str1 + " " + str3; // concatenate strings

    cout << str4 << endl;

    // we can easily coompare strings together
    if (str1 == str3)
    {
        cout << "Equal" << endl;
    }
    else
    {
        cout << "Not Equal" << endl;
    }

    // reverse the string
    reverse(str4.begin(), str4.end());

    cout << "Reversed string: " << str4 << endl;

    return 0;
}