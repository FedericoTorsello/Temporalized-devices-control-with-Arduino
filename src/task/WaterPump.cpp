#include "WaterPump.hpp"

WaterPump::WaterPump(uint8_t pin, unsigned long afterHowLongToStart, unsigned long howLongToRun)
{
    this->pin = pin;
    this->afterHowLongToStart = afterHowLongToStart;
    this->howLongToRun = howLongToRun;

    super::switchOffPin(pin);
}

WaterPump::~WaterPump()
{
}

bool WaterPump::isActiveX()
{
    return isActive;
}

void WaterPump::task(unsigned long period, void (*t)())
{
    currentMillis = millis(); // store the current time
    if (currentMillis - previousMillis >= period)
    {
        previousMillis = currentMillis; // save the last time you blinked the LED
        t();
    }
}

void WaterPump::switchOff(){
    switchOffPin(pin);
}

void WaterPump::switchOn(){
    switchOnPin(pin);
}