#include <iostream>
#include "shape.cpp"
using namespace std;

class ShapeFactory
{
public:
    Shape *getShape(string s)
    {
        if (s == "circle")
            return new Circle(5.3);
        else if (s == "rectangle")
            return new Rectangle(5.5, 10.3);
    }
};