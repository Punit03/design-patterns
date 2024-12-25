#include <iostream>
#include "button.cpp"
#include "textBox.cpp"
using namespace std;

class GUIFactory
{
public:
    virtual Button* CreateButton() const = 0;
    virtual TextBox* CreateTextBox() const = 0;
};

class WindowsFactory : public GUIFactory
{
public:
    Button* CreateButton() const override
    {
        return new WindowsButton();
    }

    TextBox* CreateTextBox() const override
    {
        return new WindowsTextBox();
    }
};

class MacFactory : public GUIFactory
{
public:
    Button* CreateButton() const override
    {
        return new MacButton();
    }

    TextBox* CreateTextBox() const override
    {
        return new MacTextBox();
    }
};