#if !defined(WATER_PUMP_HPP)
#define WATER_PUMP_HPP

#include <Arduino.h>
#include "Actions.hpp"
#include "Log.hpp"

class WaterPump : public Actions
{
private:
    bool _isTurnOn = HIGH;
    uint8_t _pin;
    unsigned long _afterHowLongToStart;
    unsigned long _howLongToRun;
    unsigned long _currentMillis;
    unsigned long _previousMillis;
    String _id;
    String _description;

public:
    WaterPump(String id, uint8_t pin, unsigned long afterHowLongToStart, unsigned long howLongToRun);
    ~WaterPump();
    void task(void (*t)());
    void turnSwitchPinOn();
    void turnSwitchPinOff();
    void runTask();
    void description();
};

#endif // WATER_PUMP_HPP
