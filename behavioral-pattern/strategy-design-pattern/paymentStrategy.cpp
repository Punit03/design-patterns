#include <iostream>
using namespace std;

class PaymentStrategy
{
public:
    virtual void Pay() const = 0;
};

class CreditCard : public PaymentStrategy
{
public:
    void Pay() const override
    {
        cout << "Paying through credit card" << endl;
    }
};

class Debitcard : public PaymentStrategy
{
public:
    void Pay() const override
    {
        cout << "Paying thorugh debit card" << endl;
    }
};
