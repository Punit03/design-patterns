#include <iostream>
#include "visitor.cpp"
using namespace std;

int main()
{
    Visitor *areaVisitor = new AreaVisitor();

    Element *circle = new Circle(3);
    Element *rectangle = new Rectangle(4, 5);

    circle->accept(areaVisitor);
    rectangle->accept(areaVisitor);
}