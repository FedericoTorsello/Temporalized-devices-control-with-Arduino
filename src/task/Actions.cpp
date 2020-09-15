#include "Actions.hpp"

Actions::Actions()
{
    Log::message("Actions ");
}

Actions::~Actions()
{
}

void Actions::switchOnPin(uint8_t pin)
{
    Log::message("Switch on pin: " + String(pin));
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void Actions::switchOffPin(uint8_t pin)
{
    Log::message("Switch off pin: " + String(pin));
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}