#include <iostream>
#include <vector>

using namespace std;

class Chai
{
private:
    string teaName;
    int servings;
    vector<string> ingredients;

public:
    Chai()
    {
        teaName = "Unknown";
        servings = 1;
        ingredients = {"Water", "Tea Leaves", "Sugar"};
    }

    Chai(string name, int servings, vector<string> ingredients)
    {
        teaName = name;
        servings = servings;
        ingredients = ingredients;
    }

    // getter
    string getTeaName()
    {
        return teaName;
    }

    // setter
    string setTeaName(string name)
    {
        teaName = name;
    }

    int getServings()
    {
        return servings;
    }

    void setServings(int servings)
    {
        servings = servings;
    }

    vector<string> getIngredients()
    {
        return ingredients;
    }

    void setIngredients(vector<string> ingredients)
    {
        ingredients = ingredients;
    }

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

    chai.setTeaName("Lemon Tea");
    chai.setServings(2);
    chai.setIngredients({"Water", "Lemon", "Sugar"});
    
    chai.displayChaiDetails();

    return 0;
}