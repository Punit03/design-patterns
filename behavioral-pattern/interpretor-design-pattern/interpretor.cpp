#include <iostream>
using namespace std;

class Expression
{
public:
    virtual ~Expression(){};
    virtual int interpret() = 0;
};

// terminal expression
class Number : public Expression
{
    int num;

public:
    Number(int num) : num(num){};

    int interpret()
    {
        return num;
    }
};

// non-terminal expression
class AddExpression : public Expression
{
    Expression *leftExpression;
    Expression *rightExpression;

public:
    AddExpression(Expression *leftExpression, Expression *rightExpression) : leftExpression(leftExpression), rightExpression(rightExpression){};
    ~AddExpression()
    {
        delete leftExpression;
        delete rightExpression;
    }
    int interpret()
    {
        return leftExpression->interpret() + rightExpression->interpret();
    }
};

class SubExpression : public Expression
{
    Expression *leftExpression;
    Expression *rightExpression;

public:
    SubExpression(Expression *leftExpression, Expression *rightExpression) : leftExpression(leftExpression), rightExpression(rightExpression){};
    ~SubExpression()
    {
        delete leftExpression;
        delete rightExpression;
    }
    int interpret()
    {
        return leftExpression->interpret() - rightExpression->interpret();
    }
};