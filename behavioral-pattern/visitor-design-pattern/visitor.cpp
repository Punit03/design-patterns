#include <iostream>
using namespace std;

class Circle;
class Rectangle;

class Visitor
{
public:
    virtual void visitCircle(Circle *c) = 0;
    virtual void visitRectangle(Rectangle *r) = 0;
    virtual ~Visitor() = default;
};

class AreaVisitor : public Visitor
{
public:
    void visitCircle(Circle *c) override;
    void visitRectangle(Rectangle *r) override;
};

class Element
{
public:
    virtual void accept(Visitor *visitor) = 0;
    virtual ~Element() = default;
};

class Circle : public Element
{
    double radius;

public:
    Circle(double r) : radius(r){};

    double getRadius()
    {
        return radius;
    }

    void accept(Visitor *visitor)
    {
        visitor->visitCircle(this);
    }
};

class Rectangle : public Element
{
    double len, width;

public:
    Rectangle(double l, double w) : len(l), width(w){};

    double getLen()
    {
        return len;
    }

    double getWidth()
    {
        return width;
    }

    void accept(Visitor *visitor)
    {
        visitor->visitRectangle(this);
    }
};

void AreaVisitor::visitCircle(Circle *circle)
{
    cout << "Area of circle: " << 3.14 * circle->getRadius() * circle->getRadius() << "\n";
}

void AreaVisitor::visitRectangle(Rectangle *rectangle)
{
    cout << "Area of rectangle: " << rectangle->getLen() * rectangle->getWidth() << "\n";
}