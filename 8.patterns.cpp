#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "\n";

    // Pattern ------------------------------------------------ 1
    /*
    A B C D
    A B C D
    A B C D
    A B C D
    */

    cout << "Pattern 1: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }
    cout << "\n";

    // Pattern ------------------------------------------------ 2
    /*
    1 2 3 4
    5 6 7 8
    9 10 11 12
    13 14 15 16
    */

    cout << "Pattern 2: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << i * j << " ";
        }
        cout << endl;
    }
    cout << "\n";

    // Pattern ------------------------------------------------ 3
    /*
    A
    B C
    D E F
    G H I J
    */

    cout << "Pattern 3: \n";
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
    cout << "\n";

    // Pattern ------------------------------------------------ 4
    /*
    1
    2 2
    3 3 3
    4 4 4 4
    */

    cout << "Pattern 4: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "\n";

    // Pattern ------------------------------------------------ 5
    /*
    A
    A B
    A B C
    A B C D
    */

    cout << "Pattern 5: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char('A' + j - 1) << " ";
        }
        cout << endl;
    }
    cout << "\n";

    // Pattern ------------------------------------------------ 6
    /*
    1
    2 1
    3 2 1
    4 3 2 1
    */

    cout << "Pattern 6: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    cout << "\n";

    // Pattern ------------------------------------------------ 7
    /*
    A A A A
      B B B
        C C
          D
    */

    cout << "Pattern 7: \n";
    for (int i = 1; i <= n; i++)
    {

        // loop for spaces
        for (int j = 1; j <= i; j++)
        {
            cout << "  ";
        }

        // loop for increasing alphabets
        for (int j = i; j <= n; j++)
        {
            cout << char('A' + i - 1) << " ";
        }

        cout << endl;
    }
    cout << "\n";

    // Pattern ------------------------------------------------ 8
    /*
            1
          1 2 1
        1 2 3 2 1
      1 2 3 4 3 2 1
    */

    cout << "Pattern 8: \n";
    for (int i = 1; i <= n; i++)
    {

        // loop for spaces
        for (int j = n - i; j >= 1; j--)
        {
            cout << "  ";
        }

        // loop for increasing numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        // loop for decreasing numbers
        for (int j = i - 1; j >= 1; j--)
        {
            cout << j << " ";
        }

        cout << endl;
    }
    cout << "\n";

    // Pattern ------------------------------------------------ 9
    /*
         *
        * *
       *   *
      *     *
       *   *
        * *
         *
     */

    cout << "Pattern 9: \n";
    // top
    for (int i = 1; i <= n; ++i)
    {
        // loop for leading spaces
        for (int j = 1; j <= n - i; ++j)
        {
            cout << " ";
        }

        // loop for stars and spaces in between
        for (int j = 1; j <= 2 * i - 1; ++j)
        {
            if (j == 1 || j == 2 * i - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // bottom
    for (int i = n - 1; i >= 1; --i)
    {
        // loop for leading spaces
        for (int j = 1; j <= n - i; ++j)
        {
            cout << " ";
        }

        // loop for stars and spaces in between
        for (int j = 1; j <= 2 * i - 1; ++j)
        {
            if (j == 1 || j == 2 * i - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    cout << "\n";

    return 0;
}