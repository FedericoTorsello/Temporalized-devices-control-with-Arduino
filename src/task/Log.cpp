#include "Log.hpp"

Log::Log(unsigned long baud)
{
    delay(1000);
    Serial.begin(baud);
}

Log::~Log()
{
}

void Log::message(String msg, bool isFrameVisible)
{
    if (isFrameVisible)
    {
        Serial.println("=========================================");
    }

    Serial.println(msg);

    if (isFrameVisible)
    {
        Serial.println("=========================================");
    }
}

void Log::error(String msg, bool isFrameVisible)
{
    if (isFrameVisible)
    {
        Serial.println("=========================================");
    }

    Serial.println("ERR: " + msg);

    if (isFrameVisible)
    {
        Serial.println("=========================================");
    }
}