#if !defined(DEVICE)
#define DEVICE

#include <Arduino.h>
#include "Actions.hpp"
#include "Log.hpp"

class Device : public Actions
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
    //void task(void (*t)());
    void turnSwitchPinOn();
    void turnSwitchPinOff();

public:
    Device(String id, uint8_t pin, unsigned long afterHowLongToStart, unsigned long howLongToRun);
    ~Device();

    virtual void runTask();
    virtual void description();
};

#endif // DEVICE