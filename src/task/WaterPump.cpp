#include "WaterPump.h"

WaterPump::WaterPump()
{
    
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
