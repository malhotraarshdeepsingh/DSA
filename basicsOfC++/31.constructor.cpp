#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Chai
{
public:
    string *teaName;
    int servings;
    vector<string> ingredients;

    // Constructor to take tea name, servings, and ingredients as inputs
    // default constructor
    Chai(string name, vector<string> ingredients, int servings)
    {
        teaName = new string(name);
        servings = servings;
        ingredients = ingredients;
    }

    Chai(const Chai &other)
    {
        teaName = new string(*other.teaName);
        servings = other.servings;
        ingredients = other.ingredients;
    }

    ~Chai()
    {
        delete teaName;
        cout << "Destructor called for " << teaName << endl;
    }

    void displayChaiDetails()
    {
        cout << "Tea Name: " << *teaName << endl;
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
    Chai lemonChai("Lemon Tea", {"Water", "Tea Leaves", "Lemon", "Sugar"}, 2);
    Chai jasmineChai("Jasmine Tea", {"Water", "Tea Leaves", "Jasmine Flower", "Sugar"}, 3);

    lemonChai.displayChaiDetails();
    jasmineChai.displayChaiDetails();

    // Copy Constructor
    Chai copiedChai = lemonChai;
    copiedChai.displayChaiDetails();

    *lemonChai.teaName = "LemonChai";
    lemonChai.displayChaiDetails();
    copiedChai.displayChaiDetails();

    return 0;
}