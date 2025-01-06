#include <iostream>

using namespace std;

class BankAccount
{
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    BankAccount(string accountHolder, int accountNumber, double initialBalance)
    {
        accountHolder = accountHolder;
        accountNumber = accountNumber;
        balance = initialBalance;
    }

    double getBalnce() const
    {
        return balance;
    }

    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposit successful. New balance: $" << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount)
    {
        if (amount > 0)
        {
            if (balance >= amount)
            {
                balance -= amount;
                cout << "Withdrawal successful. New balance: $" << balance << endl;
            }
            else
            {
                cout << "Insufficient balance. Please try again." << endl;
            }
        }
        else
        {
            cout << "Invalid withdrawal amount. Please enter a positive value." << endl;
        }
    }
};

int main()
{
    BankAccount account("John Doe", 123456, 1000);

    account.deposit(500);
    account.withdraw(2000);
    account.withdraw(500);
    account.deposit(-100);
    account.withdraw(-100);
    
    return 0;
}