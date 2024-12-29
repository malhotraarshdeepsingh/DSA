#include <iostream>
using namespace std;

int main() {

    // Pimitive Data Types
    // int
    // char
    // float
    // double
    // bool

    int age = 17; // 4 bytes

    // printing size of int data type
    cout << sizeof(age) << endl;

    // printing the value of age variable
    cout << "My age is: " << age << " years old" << endl;
    
    // char data type must store a single character in single quotes
    char grade = 'A'; // 1 byte
    cout << sizeof(grade) << endl;

    // typing f is must while storing float data type in a variable else it will be considered as double data type
    float PI = 3.14f; // 4 bytes

    // true -> 1, false -> 0
    bool isStudent = true; // 1 byte

    // double data type is of double the size of float data type
    double gradePointAverage = 9.5; // 8 bytes
    
    return 0;
}