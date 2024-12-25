#include <iostream>
using namespace std;

class TrafficLightState
{
public:
    virtual void alertTheTraffic() = 0;
    virtual TrafficLightState* setNextState() = 0;
    virtual ~TrafficLightState() {}
};

class GreenLight : public TrafficLightState
{
public:
    void alertTheTraffic() override
    {
        cout << "[Green] please go \n";
    }

    TrafficLightState* setNextState() override;
    // {
    //     state = new YellowLight();
    // }
};

class RedLight : public TrafficLightState
{

public:
    void alertTheTraffic() override
    {
        cout << "[RED] light please stop \n";
    }

    TrafficLightState* setNextState() override;
    // {
    //     state = new GreenLight();
    // }
};

class YellowLight : public TrafficLightState
{
public:
    void alertTheTraffic() override
    {
        cout << "[Yellow] light please wait \n";
    }

    TrafficLightState* setNextState() override;
    // {
    //     state = new RedLight();
    // }
};

TrafficLightState* GreenLight::setNextState()
{
    return new YellowLight();
}

TrafficLightState* RedLight::setNextState()
{
    return new GreenLight();
}

TrafficLightState* YellowLight::setNextState()
{
    return new RedLight();
}


class TrafficLight
{
    TrafficLightState *state;

public:
    TrafficLight() : state(new GreenLight()){};
    void switchTrafficLight()
    {
        state->alertTheTraffic();
        state = state->setNextState();
    }
};