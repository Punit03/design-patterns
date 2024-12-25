#include <iostream>
using namespace std;

class Vehicle
{
public:
    virtual int getFuelTankCapacity() = 0;
    virtual int getMileage() = 0;
};

class Bike : public Vehicle
{
public:
    int getFuelTankCapacity() override
    {
        return 35;
    }

    int getMileage() override
    {
        return 27;
    }
};

class NullObject : public Vehicle
{
public:
    int getFuelTankCapacity() override
    {
        return 0;
    }

    int getMileage() override
    {
        return 0;
    }
};

class VehicleFactory
{
public:
    Vehicle *getVehicle(string vehicleName)
    {
        if (vehicleName == "bike")
        {
            return new Bike();
        }
        return new NullObject();
    }
};