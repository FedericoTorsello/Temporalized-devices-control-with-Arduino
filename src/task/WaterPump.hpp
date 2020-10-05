#if !defined(WATER_PUMP_HPP)
#define WATER_PUMP_HPP

#include <Arduino.h>
//#include "Device.hpp"
#include "Actions.hpp"
#include "Log.hpp"

class WaterPump : Actions
{
private:
    bool _isTurnOn = HIGH;
    uint8_t _pin;
    unsigned long _afterHowLongToStart;
    unsigned long _howLongToRun;
    unsigned long _currentMillis;
    unsigned long _previousMillis;
    unsigned long _offset;
    String _id;
    String _description;
    //void task(void (*t)());
    void turnSwitchPinOn();
    void turnSwitchPinOff();

public:
    WaterPump(String id, uint8_t pin, unsigned long afterHowLongToStart, unsigned long howLongToRun, unsigned long offset);
    ~WaterPump();
    //WaterPump::WaterPump(Device*);
    void runTask();
    void description();
};

#endif // WATER_PUMP_HPP
