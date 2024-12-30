#include <iostream>
using namespace std;

void passByValue(int x)
{
    x = 20;
    cout << "Inside passByValue function: " << x << endl;
}

void passByReference(int &x)
{
    x = 20;
    cout << "Inside passByReference function: " << x << endl;
}

int main()
{
    int num = 10;

    passByValue(num);
    cout << "In main after passByValue: " << num << endl;

    passByReference(num);
    cout << "In main after passByReference: " << num << endl;

    return 0;
}
