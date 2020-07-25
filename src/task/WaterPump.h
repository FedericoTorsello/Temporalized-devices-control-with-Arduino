// WaterPump.h
#ifndef WATER_PUMP_H
#define WATER_PUMP_H

class WaterPump
{
private:
public:
    WaterPump();
    WaterPump(bool);
    ~WaterPump();

    bool _isActive;

    void setStatus(bool);
};

#endif // WATER_PUMP_H