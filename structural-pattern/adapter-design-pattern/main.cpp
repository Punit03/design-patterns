#include <iostream>
#include "weightMachine.cpp"
using namespace std;

int main()
{
    AnalyticalMachine machine(200);
    WeightMachine weightMachine(machine);
    weightMachine.getWeightInKg();
}