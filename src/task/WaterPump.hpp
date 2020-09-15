#if !defined(WATER_PUMP_HPP)
#define WATER_PUMP_HPP

#include <Arduino.h>
#include "Actions.hpp"
#include "Log.hpp"

class WaterPump : public Actions
{
private:
    bool isActive = false;
    uint8_t pin;
    unsigned long afterHowLongToStart = 0;
    unsigned long howLongToRun = 0;
    unsigned long currentMillis = 0;
    unsigned long previousMillis = 0;
    
public:    
    WaterPump(uint8_t pin, unsigned long afterHowLongToStart, unsigned long howLongToRun);
    ~WaterPump();    

    typedef Actions super;
    
    void task(unsigned long, void (*t)());
    void switchOff();
    void switchOn();
    bool isActiveX();
};

#endif // WATER_PUMP_HPP
