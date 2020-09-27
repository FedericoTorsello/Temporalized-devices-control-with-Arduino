#include "Log.hpp"

bool _isEnabled = false;

Log::Log(unsigned long baud)
{
    if (baud > 0)
    {
        _isEnabled = true;
        delay(1000);
        Serial.begin(baud);
    }
}

Log::~Log()
{
}

void Log::message(String msg, bool isFrameVisible)
{
    if (!_isEnabled)
    {
        return;
    }
    else
    {
        printFrame(isFrameVisible);

        Serial.print(msg + "\n");

        printFrame(isFrameVisible);
    }
}

void Log::printFrame(bool isFrameVisible)
{
    if (isFrameVisible)
    {
        Serial.print("------------------------------------------\n");
    }
    else
    {
        Serial.print('\n');
    }
}

void Log::error(String msg, bool isFrameVisible)
{
    if (!_isEnabled)
    {
        return;
    }
    else
    {
        printFrame(isFrameVisible);

        Serial.print("ERR: " + msg + "\n");

        printFrame(isFrameVisible);
    }
}