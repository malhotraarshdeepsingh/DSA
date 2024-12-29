#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Enter your age: ";
    cin >> age;


    // If-else statement examples
    if (age >= 18)
    {
        cout << "You are an adult" << endl;
    }
    else
    {
        cout << "You are a minor" << endl;
    }

    // If-else-if statement practice questions

    // check to find character is lowercase or uppercase
    char character;
    cout << "Enter a character: ";
    cin >> character;

    if (character >= 'a' && character <= 'z')
    {
        cout << character << " is a lowercase letter" << endl;
    }
    else if (character >= 'A' && character <= 'Z')
    {
        cout << character << " is an uppercase letter" << endl;
    }
    else
    {
        cout << character << " is not a letter" << endl;
    }


    // Ternary Operators
    // Syntax: condition ? expression1 : expression2

    int score = 85;
    cout << (score >= 50 ? "Pass" : "Fail") << endl;


    // Switch Operator
    // Syntax: switch (expression) { case value1: statement1; break; case value2: statement2; break; default: statement3; }

    int day;
    cout << "Enter a day number: ";
    cin >> day;
    
    switch (day)
    {
    
    case 1:
        cout << "Monday" << endl;
        break;
        
    case 2:
        cout << "Tuesday" << endl;
        break;
        
    case 3:
    cout << "Wednesday" << endl;
        break;
        
    case 4:
        cout << "Thursday" << endl;
        break;
        
    case 5:
        cout << "Friday" << endl;
        break;
        
    case 6:
        cout << "Saturday" << endl;
        break;
        
    case 7:
        cout << "Sunday" << endl;
        break;
        
    default:
        cout << "Invalid day" << endl;
        break;
    
    }

    return 0;
}