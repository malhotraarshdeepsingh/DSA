#include <iostream>
#include <string>

using namespace std;

class Tea
{
public:
    virtual void prepareIngrediants() = 0; // pure virtual function
    virtual void brew() = 0;
    virtual void serve() = 0;

    void makeTea()
    {
        prepareIngrediants();
        brew();
        serve();
    }
};

class GreenTea : public Tea
{
public:
    void prepareIngrediants() override
    {
        cout << "Preparing Green Tea Ingrediants" << endl;
    }

    void brew() override
    {
        cout << "Brewing Green Tea" << endl;
    }

    void serve() override
    {
        cout << "Serving Green Tea" << endl;
    }
};

class BlackTea : public Tea
{
    void prepareIngrediants() override
    {
        cout << "Preparing Black Tea Ingrediants" << endl;
    }
    
    void brew() override
    {
        cout << "Brewing Black Tea" << endl;
    }
    
    void serve() override
    {
        cout << "Serving Black Tea" << endl;
    }
};

int main()
{
    GreenTea greentea;
    BlackTea blacktea;

    greentea.makeTea();
    blacktea.makeTea();

    return 0;
}