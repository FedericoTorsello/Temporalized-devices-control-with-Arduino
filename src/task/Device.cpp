#include "Device.hpp"

Device::Device(String id, uint8_t pin, unsigned long afterHowLongToStart, unsigned long howLongToRun)
{
    this->_id = id;
    this->_pin = pin;
    this->_afterHowLongToStart = afterHowLongToStart;
    this->_howLongToRun = howLongToRun;
}

Device::~Device()
{
}

/*void Device::task(void (*t)())
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
}*/

void Device::turnSwitchPinOff()
{
    _isTurnOn = LOW;
    switchOnPin(_pin); // Turn it off
    description();
}

void Device::turnSwitchPinOn()
{
    _isTurnOn = HIGH;
    switchOffPin(_pin); // Turn it on
    description();
}

void Device::description()
{
}

void Device::runTask()
{
}

/*void Device::description()
{
    String status = _isTurnOn ? "YES" : "NO";
    String msg = "WATER_PUMP:\t\t\t" + String(_id) + "\nPIN N°:\t\t\t\t" + String(_pin) +
                 "\nIS TURN ON:\t\t\t" + status +
                 +"\nAFTER HOW LONG TO START:\t" + String(_afterHowLongToStart) + " ms" +
                 +"\nHOW LONG TO RUN:\t\t" + String(_howLongToRun) + " ms";

    Log::message(msg);
}*/

/*void Device::runTask()
{
    _currentMillis = millis();

    if ((_isTurnOn == HIGH) && (_currentMillis - _previousMillis >= _howLongToRun))
    {
        turnSwitchPinOff();

        _previousMillis = _currentMillis;
    }
    else if ((_isTurnOn == LOW) && (_currentMillis - _previousMillis >= _afterHowLongToStart))
    {
        turnSwitchPinOn();

        _previousMillis = _currentMillis;
    }
}*/