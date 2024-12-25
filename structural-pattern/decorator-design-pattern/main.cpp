#include <iostream>
#include "pizza.cpp"
using namespace std;

int main()
{
    Pizza *basePizza = new VeggiePizza();
    Pizza *pizzaWithCheeseToppings = new CheeseTopping(basePizza);
    cout << "Cost: " << pizzaWithCheeseToppings->cost() << endl;
    Pizza *pizzaWithCheeseAndMushrooms = new Mushrooms(pizzaWithCheeseToppings);
    cout << "Cost: " << pizzaWithCheeseAndMushrooms->cost() << endl;
}