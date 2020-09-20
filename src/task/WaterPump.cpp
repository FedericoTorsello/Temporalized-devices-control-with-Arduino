#include "WaterPump.hpp"

WaterPump::WaterPump(String id, uint8_t pin, unsigned long afterHowLongToStart, unsigned long howLongToRun)
{
    this->_id = id;
    this->_pin = pin;
    this->_afterHowLongToStart = afterHowLongToStart;
    this->_howLongToRun = howLongToRun;

    if (pin == 0)
    {
        Log::error("PIN NOT SET!");
    }
}

WaterPump::~WaterPump()
{
}

void WaterPump::task(void (*t)())
{
    _currentMillis = millis();
    if ((_isTurnOn == HIGH) && (_currentMillis - _previousMillis >= _afterHowLongToStart))
    {
        t();

        _previousMillis = _currentMillis; // Remember the time
    }
    else if ((_isTurnOn == LOW) && (_currentMillis - _previousMillis >= _howLongToRun))
    {
        t();

        _previousMillis = _currentMillis; // Remember the time
    }
}

void WaterPump::turnSwitchPinOff()
{
    _isTurnOn = LOW; // Turn it off
    switchOnPin(_pin);
    description();    
}

void WaterPump::turnSwitchPinOn()
{
    _isTurnOn = HIGH; // Turn it on
    switchOffPin(_pin);
    description();
}

void WaterPump::description()
{
    String status = _isTurnOn ? "YES" : "NO";
    String msg = "WATER_PUMP N°:\t\t\t" + String(_id) + "\nPIN N°:\t\t\t\t" + String(_pin) +
                 "\nIS SWITCH PIN TURN ON:\t\t" + status +
                 +"\nAFTER HOW LONG TO START:\t" + String(_afterHowLongToStart) + " ms" +
                 +"\nHOW LONG TO RUN:\t\t" + String(_howLongToRun) + " ms";

    Log::message(msg);
}

void WaterPump::runTask()
{
    _currentMillis = millis();
    if ((_isTurnOn == HIGH) && (_currentMillis - _previousMillis >= _afterHowLongToStart))
    {
        turnSwitchPinOff();

        _previousMillis = _currentMillis; // Remember the time
    }
    else if ((_isTurnOn == LOW) && (_currentMillis - _previousMillis >= _howLongToRun))
    {
        turnSwitchPinOn();

        _previousMillis = _currentMillis; // Remember the time
    }
}