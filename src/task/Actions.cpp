#include "Actions.hpp"

Actions::Actions() {}

Actions::~Actions() {}

void Actions::switchOnPin(uint8_t pin)
{
    Log::message("ACTION:\tSwitch off pin:\t\t" + String(pin));
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}

void Actions::switchOffPin(uint8_t pin)
{
    Log::message("ACTION:\tSwitch on pin:\t\t" + String(pin));
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}