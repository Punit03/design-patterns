#include <iostream>
using namespace std;

class Shape
{
public:
    virtual float calculateArea() const = 0;
};

class Circle : public Shape
{
    float radius;

public:
    Circle(float r) : radius(r) {}
    float calculateArea() const override
    {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape
{
    float length, width;

public:
    Rectangle(float l, float w) : length(l), width(w) {}
    float calculateArea() const override
    {
        return length * width;
    }
};