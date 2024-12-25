#include <iostream>
#include "observable/iphoneObservable.cpp"
using namespace std;

int main()
{
    StockObservable* iphoneObservable = new IphoneObservable();
    iphoneObservable->add(new SMSNotifier("9876543210", iphoneObservable));
    iphoneObservable->updateStockCount(5);
}