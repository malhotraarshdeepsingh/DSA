#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tea
{
protected:
    string teaName;
    int servings;

public:
    Tea(string name, int servings) : teaName(name), servings(servings)
    {
        cout << "Tea constructor called" << teaName << endl;
    }

    virtual void brew() const
    {
        cout << "Brewing tea " << teaName << endl;
    }

    virtual void serve() const
    {
        cout << "Serving " << servings << "cups of tea" << endl;
    }

    virtual ~Tea()
    {
        cout << "Tea destructor called" << teaName << endl;
    }
};

class LemonTea : public Tea
{
public:
    LemonTea(int servings) : Tea("Lemon Tea", servings)
    {
        cout << "Lemon Tea constructor called" << endl;
    }

    void brew() const override
    {
        cout << "Brewing lemon tea" << teaName << endl;
    }

    ~LemonTea()
    {
        cout << "Lemon Tea destructor called" << endl;
    }
};

class MasalaTea : public Tea
{
public:
    MasalaTea(int servings) : Tea("Masala Tea", servings)
    {
        cout << "Masala Tea constructor called" << endl;
    }

    void brew() const override final
    {
        cout << "Brewing MasalaTea" << teaName << endl;
    }

    ~MasalaTea()
    {
        cout << "Masala Tea destructor called" << endl;
    }
};

int
main()
{
    Tea *tea1 = new LemonTea(2);
    Tea *tea2 = new MasalaTea(4);

    tea1->brew();
    tea1->serve();

    tea2->brew();
    tea2->serve();

    delete tea1;
    delete tea2;

    return 0;
}