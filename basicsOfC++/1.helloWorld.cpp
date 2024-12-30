// #include <iostream> is a preprocessor directive that tells the compiler to include the iostream standard file.
#include <iostream>

// The line below eliminates the need to prefix elements from the std namespace with 'std::'
// using namespace std;
// std is a standard library that contains all the classes, functions and objects in C++.

// The main function is the entry point of a C++ program.

// Custom namespace declarations
namespace newCustom {
    void display(){}
}

int main()
{
    // cout is used to print output to the console.
    // cout << "Hello World";

    // The << operator is used to insert data into the output stream.
    std::cout << "Hello World" << std::endl;
    // std::endl is a function that outputs a newline character and flushes the output buffer.

    // "\n" is slightly faster than std::endl
    // std::cout << "Hello World" << "\n";

    // The return statement is used to return a value from a function.
    // In this case, the main function must return a integer value.
    // 0 means the program executed successfully.
    // Any other value can be used to indicate an error. 0 is often used to indicate success.

    newCustom::display();

    return 0;
}