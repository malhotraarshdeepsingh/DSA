#include <iostream>
using namespace std;

int main()
{
    // while, for, do-while

    // Print numbers from 1 to 10

    // while loop
    int i = 1;
    while (i <= 10)
    {
        cout << i << "\n";
        i++;
    }

    // for loop
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\n";
    }

    // do-while loop
    int j = 1;
    do
    {
        cout << j << "\n";
        j++;
    } while (j <= 10);



    // Sum of all odd numbers from 1 to N

    int n;
    cout << "Enter a number: ";
    cin >> n;
    int sum = 0;
    int a = 1;
    while (a <= n)
    {
        sum += a;
        a += 2;
    }
    cout << "Sum of all odd numbers from 1 to " << n << " is " << sum << endl;



    // Check if a number is prime or not

    int num;
    cout << "Enter a number: ";
    cin >> num;
    bool isPrime = true;
    if (num <= 1)
    {
        isPrime = false;
    }
    else
    {
        for (int i = 2; i <= num / 2; i++)
        {
            if (num % i == 0)
            {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
    {
        cout << num << " is a prime number." << endl;
    }
    else
    {
        cout << num << " is not a prime number." << endl;
    }



    // Print factorial of a number

    int factorial;
    cout << "Enter a number: ";
    cin >> factorial;
    int fact = 1;
    for (int i = 1; i <= factorial; i++)
    {
        fact *= i;
    }
    cout << "Factorial of " << factorial << " is " << fact << endl;
    
    return 0;
}