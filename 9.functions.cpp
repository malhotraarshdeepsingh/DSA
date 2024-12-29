#include <iostream>
using namespace std;

// Function Syntax
// return_type function_name(parameter1, parameter2) {
//     // function body
// }

// Calculate the sum of digits of a number
int sumOfDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

// Calculate nCr 
int nCr(int n, int r)
{
    int numerator = 1, denominator = 1;
    for (int i = 1; i <= r; i++)
    {
        numerator *= (n - i + 1);
        denominator *= i;
    }
    return numerator / denominator;
}

int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    cout << "Sum of digits of " << number << " is " << sumOfDigits(number) << endl;

    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    
    cout << "nCr(" << n << ", " << r << ") is " << nCr(n, r) << endl;

    return 0;
}