#include <iostream>
#include "trafficLight.cpp"
#include <thread>
#include <chrono>

using namespace std;

int main()
{
    TrafficLight *trafficLight = new TrafficLight();

    while (true)
    {
        trafficLight->switchTrafficLight();
        this_thread::sleep_for(chrono::seconds(3));
    }
}