#include <iostream>
#include "shoppingCart.cpp"
using namespace std;

int main()
{
    Shoppingcart cart = Shoppingcart();
    PaymentStrategy *paymentMethod = new Debitcard();
    cart.setPaymentmethod(paymentMethod);
    cart.checkout();
}