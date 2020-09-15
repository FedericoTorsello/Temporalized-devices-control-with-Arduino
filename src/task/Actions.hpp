#if !defined(ACTIONS_HPP)
#define ACTIONS_HPP

#include <Arduino.h>
#include "Log.hpp"

class Actions
{
private:
    /* data */
public:
    Actions();
    ~Actions();
protected:
    void switchOnPin(uint8_t pin);
    void switchOffPin(uint8_t pin);
};

#endif // ACTIONS_HPP
