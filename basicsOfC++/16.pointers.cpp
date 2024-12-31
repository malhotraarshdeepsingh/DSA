#include <iostream>
using namespace std;

int main()
{
    // A pointer is a variable that stores the memory address of another variable. It is a powerful feature in C/C++ that allows you to directly access and manipulate memory.
    // * --- Value at
    // & --- Address of

    int a = 10;
    int *p = &a;
    int **q = &p;

    cout << *p << "\n";
    cout << **q << "\n";
    cout << p << "\n";
    cout << *q << "\n";

    // Pointer arithmetic allows performing operations like addition, subtraction, increment, and decrement on pointers.

    // p++
    // Moves the pointer to the next memory location based on the data type it points to.
    p++;
    cout << p << "\n";

    // p--
    // Moves the pointer to the previous memory location based on the data type it points to.
    p--;
    cout << p << "\n";

    // p + n, p - n
    // Moves the pointer n memory locations ahead or behind based on the data type it points to.
    cout << p + 1 << "\n";

    // p1 - p2
    // Returns the number of memory locations between p1 and p2 based on the data type they point to.
    cout << p - *q << "\n";

    // Pointers are used in various scenarios like dynamic memory allocation, arrays, functions, and data structures like linked lists, trees, graphs, etc.
    // Pointers are also used in low-level programming, system programming, and embedded systems where direct memory access is required.

    int array[] = {0, 1, 2, 3, 4, 5};
    int *z = array;

    cout << *(z + 4) << "\n";
    cout << z[4] << "\n";
    z++;
    cout << *z << "\n";

    return 0;
}