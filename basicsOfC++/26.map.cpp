#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> m;
    // key is unique and is stored in ascending order

    m["apple"] = 10;
    m["banana"] = 20;
    m["cherry"] = 30;
    m["dates"] = 40;
    m["elderberry"] = 50;

    m.insert({"oranges", 70});

    for (auto it : m)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << "count of oranges: " << m.count("oranges") << endl;
    // return the number of instances with key as oranges

    if (m.find("oranges") != m.end())
    {
        cout << "oranges found" << endl;
    }

    // Other maps 

    // multi map 
    // we can store multiple keys 
    // multimap<string, int> mm;

    // unordered map
    // unordered_map<string, int> um;
    // stores in a random order
    // as it is unordered we have constant time complexity for search, insert and delete operations
    
    return 0;
}