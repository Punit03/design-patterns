#include <iostream>
using namespace std;

class IWeightMachine
{
public:
    virtual int getWeight() = 0;
};

class AnalyticalMachine : public IWeightMachine
{
    int weight;

public:
    AnalyticalMachine(int weight) : weight(weight){};
    int getWeight()
    {
        return weight;
    }
};

class IWeight
{
public:
    virtual void getWeightInKg() = 0;
};

class WeightMachine : public IWeight
{
    AnalyticalMachine weighingMachine;

public:
    WeightMachine(AnalyticalMachine machine) : weighingMachine(machine) {}
    void getWeightInKg()
    {
        cout << "Your weight is: " << weighingMachine.getWeight() * 0.45 << "\n";
    }
};