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

    static void message(String msg, bool isFrameVisible = true);
    static void error(String msg, bool isFrameVisible = true);
};

#endif // LOG_HPP
