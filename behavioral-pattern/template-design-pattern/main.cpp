#include <iostream>
#include "template.cpp"
using namespace std;

int main()
{
    PaymentFlow *payToMerchant = new PaytToMerchant();
    payToMerchant->sendMoney();

    PaymentFlow *payToUser = new PaytToUser();
    payToUser->sendMoney();
}