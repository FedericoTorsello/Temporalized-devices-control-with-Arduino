#if !defined(LOG_HPP)
#define LOG_HPP

#include <Arduino.h>

class Log
{
private:
    /* data */
public:
    Log(unsigned long);
    ~Log();

    static void message(String);
    static void error(String);
};

#endif // LOG_HPP
