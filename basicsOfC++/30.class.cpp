#include <iostream>
#include <vector>

using namespace std;

class Chai
{
public:
    string teaName;
    int servings;
    vector<string> ingredients;

    void displayChaiDetails()
    {
        cout << "Tea Name: " << teaName << endl;
        cout << "Servings: " << servings << endl;
        cout << "Ingredients: ";
        for (string ingredient : ingredients)
        {
            cout << ingredient << " ";
        }
        cout << endl;
    }
};

int main()
{
    Chai chai;

    chai.teaName = "Lemon Tea";
    chai.servings = 2;
    chai.ingredients = {"Water", "Tea Leaves", "Lemon", "Sugar"};
    chai.displayChaiDetails();
    
    return 0;
}