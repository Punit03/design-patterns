#include <iostream>
using namespace std;

class PaymentFlow
{
public:
    virtual void validateRequest() = 0;
    virtual void addProcessingFee() = 0;
    virtual void debitAmount() = 0;
    virtual void crditAmount() = 0;

    void sendMoney()
    {
        validateRequest();
        addProcessingFee();
        debitAmount();
        crditAmount();
    }
};

class PaytToMerchant : public PaymentFlow
{
public:
    void validateRequest()
    {
        cout << "Logic Validated" << "\n";
    }

    void addProcessingFee()
    {
        cout << "Not deducting any processing fee" << "\n";
    }

    void debitAmount()
    {
        cout << "Debiting amount" << "\n";
    }

    void crditAmount()
    {
        cout << "Crditing amount" << "\n";
    }
};

class PaytToUser : public PaymentFlow
{
public:
    void validateRequest()
    {
        cout << "Logic Validated" << "\n";
    }

    void addProcessingFee()
    {
        cout << "Deducting processing fee 0.3*amount" << "\n";
    }

    void debitAmount()
    {
        cout << "Debiting amount" << "\n";
    }

    void crditAmount()
    {
        cout << "Crditing amount" << "\n";
    }
};