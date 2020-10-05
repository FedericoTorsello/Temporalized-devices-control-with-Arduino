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
    virtual void switchOnPin(uint8_t pin) final;
    virtual void switchOffPin(uint8_t pin) final;
};

#endif // ACTIONS_HPP
