#include <iostream>
#include "vehicle.cpp"

using namespace std;

int main()
{
    VehicleFactory *vehicleFactory = new VehicleFactory();
    Vehicle *bike = vehicleFactory->getVehicle("bike");
    Vehicle *car = vehicleFactory->getVehicle("car");

    cout << "Bike fuel tank capacty: " << bike->getFuelTankCapacity() << "\n";
    cout << "Bike mileage: " << bike->getMileage() << "\n";

    cout << "Car fuel tank capacty: " << car->getFuelTankCapacity() << "\n";
    cout << "Car mileage: " << car->getMileage() << "\n";
}