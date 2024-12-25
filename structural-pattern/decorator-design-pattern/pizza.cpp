#include <iostream>
using namespace std;

class Pizza
{
public:
    virtual void Create() const = 0;
    virtual float cost() = 0;
};

class CheesePizza : public Pizza
{
public:
    void Create() const override
    {
        cout << "Creating CheesePizza" << endl;
    }
    float cost() override
    {
        return 100;
    }
    ~CheesePizza() {}
};

class VeggiePizza : public Pizza
{
public:
    void Create() const override
    {
        cout << "Creating VeggirPizza" << endl;
    }
    float cost() override
    {
        return 200;
    }
    ~VeggiePizza() {}
};

class Toppings : public Pizza
{
public:
};

class CheeseTopping : public Toppings
{
    Pizza *basePizza;

public:
    CheeseTopping(Pizza *basePizza) : basePizza(basePizza) {}
    void Create() const override
    {
        cout << "Adding CheeseTopping" << endl;
    }
    float cost() override
    {
        return basePizza->cost() + 30;
    }
    ~CheeseTopping() {}
};

class Mushrooms : public Toppings
{
    Pizza *basePizza;

public:
    Mushrooms(Pizza *basePizza) : basePizza(basePizza) {}
    void Create() const override
    {
        cout << "Adding Mushrooms" << endl;
    }
    float cost() override
    {
        return basePizza->cost() + 22;
    }
    ~Mushrooms() {}
};