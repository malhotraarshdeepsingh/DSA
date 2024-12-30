#include <iostream>
using namespace std;

int main()
{
    // There are two ways to covert data types
    // 1. Implicit Type Casting ( Type Conversion )
    // 2. Explicit Type Casting ( Type Casting )

    // Implicit Type Casting
    // In Implicit Type Casting, the compiler automatically converts one data type into another without any user intervention.
    // The data type with smaller size is converted into data type with larger size.
    // For example, int -> float, float -> double, char -> int, etc.

    // Explicit Type Casting
    // In Explicit Type Casting, the user manually converts one data type into another.
    // The data type with larger size is converted into data type with smaller size.
    // For example, double -> float, float -> int, int -> char, etc.

    // Implicit Type Casting Example
    char grade = 'A';
    int value = grade;
    cout << value << endl; // 65

    // Explicit Type Casting Example
    double price = 100.999999;
    int newPrice = (int)price;
    cout << newPrice << endl; // 100
    // Note: In Explicit Type Casting, the data is not rounded off. It is simply truncated.
}