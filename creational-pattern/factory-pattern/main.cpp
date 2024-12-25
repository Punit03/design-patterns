#include <iostream>
#include "shapeFactory.cpp"
using namespace std;

int main()
{
    ShapeFactory *shapeFactory = new ShapeFactory();
    Shape *shape = shapeFactory->getShape("circle");
    cout << "area of the shape:" << shape->calculateArea() << endl;
}