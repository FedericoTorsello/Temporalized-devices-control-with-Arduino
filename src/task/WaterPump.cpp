#include "WaterPump.h"

WaterPump::WaterPump()
{
    this->_isActive = false;
}

WaterPump::WaterPump(bool isActive)
{
    this->_isActive = isActive;
}

WaterPump::~WaterPump()
{
}

void WaterPump::setStatus(bool newValue)
{
    this->_isActive = newValue;
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
