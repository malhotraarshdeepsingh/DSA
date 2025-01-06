#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Chai
{
private:
    string teaName;
    int servings;

public:
    Chai(string name, int servings) : teaName(teaName), servings(servings) {}

    friend bool compareServings(const Chai &a, const Chai &b);

    void display() const
    {
        cout << "Tea Name: " << teaName << endl;
        cout << "Servings: " << servings << endl;
    }
};

bool compareServings(const Chai &a, const Chai &b)
{
    return a.servings > b.servings;
}

int main()
{
    Chai chai("Lemon Tea", 2);
    chai.display();

    Chai chai2("Jasmine Tea", 3);
    chai2.display();

    if (compareServings(chai, chai2))
    {
        cout << "Chai 1 has more servings" << endl;
    }
    else
    {
        cout << "Chai 2 has more servings" << endl;
    }

    return 0;
}