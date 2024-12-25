#include <iostream>
#include "GUIFactory.cpp"
using namespace std;

int main()
{
    GUIFactory* macFactory = new MacFactory();
    macFactory->CreateButton()->render();
    macFactory->CreateTextBox()->render();
}
