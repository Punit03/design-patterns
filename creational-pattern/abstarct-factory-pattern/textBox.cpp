#include <iostream>
using namespace std;

class TextBox
{
public:
    virtual void render() const = 0;
    virtual ~TextBox(){};
};

class WindowsTextBox : public TextBox
{
public:
    void render() const override
    {
        cout << "render windows text box" << endl;
    }
};

class MacTextBox : public TextBox
{
public:
    void render() const override
    {
        cout << "render mac text box" << endl;
    }
};