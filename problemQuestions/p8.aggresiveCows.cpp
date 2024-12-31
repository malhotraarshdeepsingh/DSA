// Aggresive Cows Problem 
// Assign C cows to N stalls such that min distance between them is largest possible.
// Return largest minimum distance.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Function to find the maximum distance between cows
int maxDistance(vector<int> stalls, int n, int c)
{
    sort(stalls.begin(), stalls.end()); 

    int max_distance = stalls[n - 1] - stalls[0]; 

    int min_distance = stalls[1] - stalls[0]; 

    for (int i = 2; i <= n - c; i++)
        min_distance = min(min_distance, stalls[i] - stalls[i - 1]); 

    return max(max_distance, min_distance); 
}

// Function to find the number of cows that can be placed at max distance
int findCows(vector<int> stalls, int n, int max_distance)
{
    int cows = 1; 
    int last_cow_position = stalls[0]; 

    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last_cow_position >= max_distance)
        {
            cows++;
            last_cow_position = stalls[i];
        }
    }

    return cows; 
}

int main()
{
    int n, c;
    cin >> n >> c; 

    vector<int> stalls(n); 

    for (int i = 0; i < n; i++)
        cin >> stalls[i]; 

    int max_distance = maxDistance(stalls, n, c); 

    cout << findCows(stalls, n, max_distance) << endl; 

    return 0; 
}