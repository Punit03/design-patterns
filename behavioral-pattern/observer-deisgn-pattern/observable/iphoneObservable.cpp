#include <iostream>
#include <vector>
using namespace std;

class Notifier
{
public:
    virtual void notify() const = 0;
};

class StockObservable
{
public:
    virtual void add(Notifier *notifier) = 0;
    virtual void remove(Notifier *notifier) = 0;
    virtual void notifySubscribers() = 0;
    virtual void updateStockCount(int newStockCount) = 0;
    virtual int getstockCount() = 0;
};

class IphoneObservable : public StockObservable
{
    vector<Notifier *> observers;
    int totalStocks;

public:
    IphoneObservable() : totalStocks(0), observers() {}
    void add(Notifier *notifier) override
    {
        observers.push_back(notifier);
    }
    void remove(Notifier *notifier) override
    {
        observers.erase(find(observers.begin(), observers.end(), notifier));
    }
    void notifySubscribers() override
    {
        for (auto observer : observers)
        {
            observer->notify();
        }
    }

    void updateStockCount(int newStocks) override
    {
        int prevStocks = totalStocks;
        totalStocks = newStocks;
        if (prevStocks == 0 && newStocks > 0)
        {
            notifySubscribers();
        }
    }

    int getstockCount() override
    {
        return totalStocks;
    }
    ~IphoneObservable() {}
};

class SMSNotifier : public Notifier
{
    string number;
    StockObservable *stock;

public:
    SMSNotifier(string number, StockObservable *stock) : number(number), stock(stock) {}
    void notify() const override
    {
        cout << "Hurry up stock updated " << stock->getstockCount() << " added \nSending SMS in number " << number << endl;
    }
};

class EmailNotifier : public Notifier
{
    string email;
    StockObservable *stock;

public:
    EmailNotifier(string email, StockObservable *stock) : email(email), stock(stock) {}
    void notify() const override
    {
        cout << "Hurry up stock updated " << stock->getstockCount() << " added \nSending Email in number " << email << endl;
    }
};