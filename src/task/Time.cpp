#include "Time.hpp"

Time::Time(/* args */)
{
}

Time::~Time()
{
}

unsigned long Time::day(uint8_t days)
{
    return days * DAY;
}

unsigned long Time::hour(uint8_t hours)
{
    return hours * HOUR;
}

unsigned long Time::minute(uint8_t minutes)
{
    return minutes * MINUTE;
}

unsigned long Time::second(uint8_t seconds)
{
    return seconds * SECOND;
}