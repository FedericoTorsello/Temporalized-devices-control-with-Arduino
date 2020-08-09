// WaterPump.h
#ifndef WATER_PUMP_H
#define WATER_PUMP_H

#include <Arduino.h>

class WaterPump
{
private:
    unsigned long currentMillis;
    unsigned long previousMillis; 
public:
    WaterPump();
    WaterPump(bool);
    ~WaterPump();

    bool _isActive;

    void setStatus(bool);
    void task(unsigned long, void (*t)());
};

#endif // WATER_PUMP_H