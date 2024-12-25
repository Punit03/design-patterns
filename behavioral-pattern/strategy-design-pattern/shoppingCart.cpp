#include <iostream>
#include "paymentStrategy.cpp"
using namespace std;

class Shoppingcart
{
    PaymentStrategy *paymentMethod;

public:
    void setPaymentmethod(PaymentStrategy *choosenPayment)
    {
        this->paymentMethod = choosenPayment;
    }
    void checkout()
    {
        paymentMethod->Pay();
    }
};