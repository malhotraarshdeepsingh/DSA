#include <iostream>
using namespace std;

int main(){
    // 1. Arithmetic Operators
    // 2. Relational Operators
    // 3. Logical Operators
    // 4. Unarb Operators
    // 5. Bitwise Operators
    
    // Arithmetic Operators
    // +, -, *, /, %,
        
    int a = 10;
    int b = 20;

    int sum = a + b;
    int difference = a - b;
    int product = a * b;
    int quotient = a / b;
    int remainder = a % b;

    // Unarb Operators
    // ++, --

    a++;
    int increment = a;
    b--;
    int decrement = b;
    
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;
    cout << "Remainder: " << remainder << endl;
    cout << "Increment: " << increment << endl;
    cout << "Decrement: " << decrement << endl;
    
    // Relational Operators
    // ==, !=, >, <, >=, <=

    bool isEqual = a == b;
    bool isNotEqual = a != b;
    bool isGreater = a > b;
    bool isLess = a < b;
    bool isGreaterOrEqual = a >= b;
    bool isLessOrEqual = a <= b;
    
    cout << "Is Equal: " << isEqual << endl;
    cout << "Is Not Equal: " << isNotEqual << endl;
    cout << "Is Greater: " << isGreater << endl;
    cout << "Is Less: " << isLess << endl;
    cout << "Is Greater Or Equal: " << isGreaterOrEqual << endl;
    cout << "Is Less Or Equal: " << isLessOrEqual << endl;
    
    // Logical Operators
    // && (AND), || (OR), ! (NOT)

    bool andOperator = a > 0 && b > 0;
    bool orOperator = a > 0 || b > 0;
    bool notOperator = !(a > 0);
    
    cout << "AND Operator: " << andOperator << endl;
    cout << "OR Operator: " << orOperator << endl;
    cout << "NOT Operator: " << notOperator << endl;

    // Bitwise Operators
    // &, |, ^, ~, <<, >>

    int andBitwise = a & b;
    int orBitwise = a | b;
    int aorBitwise = a ^ b;
    int notBitwise = ~a;
    int leftShift = a << 1;
    int rightShift = a >> 1;
    
    cout << "AND Bitwise: " << andBitwise << endl;
    cout << "OR Bitwise: " << orBitwise << endl;
    cout << "aOR Bitwise: " << aorBitwise << endl;
    cout << "NOT Bitwise: " << notBitwise << endl;
    cout << "Left Shift: " << leftShift << endl;
    cout << "Right Shift: " << rightShift << endl;
    
    return 0;
}