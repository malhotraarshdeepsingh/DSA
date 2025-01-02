#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(20);
    s.insert(30);

    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;

    s.erase(20);
    for (auto it : s)
    {
        cout << it << " ";
    }
    cout << endl;

    s.clear();
    cout << "Size of set after clearing: " << s.size() << endl;

    // set also sorts the elements in ascending order and does not allow duplicates
    // inbuilt functions have time complexity of O(log n)

    // lower_bound returns the address of the element at the position or the next greater element
    // upper_bound returns the address of the next greater element

    // multi set
    // allows duplicates
    // multiset<int> ms;

    // unordered set
    // unordered_set<int> us;
    // stores in a random order
    // as it is unordered we have constant time complexity for search, insert and delete operations

    return 0;
}