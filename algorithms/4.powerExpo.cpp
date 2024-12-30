#include <iostream>
#include <vector>
using namespace std;

// Function to calculate x raised to the power of n using binary exponentiation
double power(double x, int n)
{

    if (n == 0)
        return 1;
    
    if (x == 0)
        return 0;

    if (x == 1)
        return x;
    
    if (x == -1 && n % 2 == 0)
        return 1;
    
    if (x == -1 && n % 2 != 0)
        return -1;

    long binaryExponent = n;

    // If n is negative, take the reciprocal of x and change the sign of the binary exponent
    if (binaryExponent < 0)
    {
        x = 1 / x;
        binaryExponent = -binaryExponent;
    }

    // Convert n to binary representation

    vector<int> binaryRepresentation;
    long tempExponent = binaryExponent;
    
    while (tempExponent > 0)
    {
        binaryRepresentation.push_back(tempExponent % 2);
        tempExponent /= 2;
    }

    double result = 1;

    while (binaryExponent > 0)
    {
        if (binaryExponent % 2 == 1)
            result *= x;
        x *= x;
        binaryExponent /= 2;
    }

    return result;
    // Time complexity: O(log n)
    // Space complexity: O(1)

}

int maxProfit(vector <int> &prices)
{
    int maxProfit = 0, bestBuy = prices[0];

    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] > bestBuy)
            maxProfit = max(maxProfit, prices[i] - bestBuy);
        bestBuy = min(bestBuy, prices[i]);            
    }

    return maxProfit;
}

int main()
{
    double x;
    int n;
    cout << "Enter the base x: ";
    cin >> x;
    cout << "Enter the power n: ";
    cin >> n;

    double result = power(x, n);

    cout << x << "^" << n << " = " << result << endl;

    vector <int> prices = {7, 1, 5, 3, 6, 4};

    int maxProfitValue = maxProfit(prices);
    
    cout << "Maximum profit: " << maxProfitValue << endl;

    return 0;
}