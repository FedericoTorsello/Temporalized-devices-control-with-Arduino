#if !defined(TIME_HPP)
#define TIME_HPP

#include <Arduino.h>

class Time
{
private:
    static const unsigned long SECOND = 1000UL;
    static const unsigned long MINUTE = 60U * SECOND;
    static const unsigned long HOUR = 60U * MINUTE * SECOND;
    static const unsigned long DAY = 24U * HOUR * SECOND;

public:
    Time(/* args */);
    ~Time();

    static unsigned long day(uint8_t days);
    static unsigned long hour(uint8_t hours);
    static unsigned long minute(uint8_t minutes);
    static unsigned long second(uint8_t seconds);
};

#endif // TIME_HPP
