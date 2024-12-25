#include <iostream>
#include "interpretor.cpp"
using namespace std;

int main()
{
    cout << "Evalauting expression: (1-2+5) \n";
    Expression *expression = new AddExpression(
        new SubExpression(
            new Number(1),
            new Number(2)),
        new Number(5));
    cout << "Expression evaluated: " << expression->interpret()<<"\n";
}
