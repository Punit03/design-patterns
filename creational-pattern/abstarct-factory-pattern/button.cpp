#include <iostream>
using namespace std;

class Button
{
public:
    virtual void render() const = 0;
    virtual ~Button() {}
};

class WindowsButton : public Button
{
public:
    void render() const override
    {
        cout << "render windows button" << endl;
    }
};

class MacButton : public Button
{
public:
    void render() const override
    {
        cout << "render mac button" << endl;
    }
};