#include "Log.hpp"

Log::Log(unsigned long baud)
{
    delay(1000);
    Serial.begin(baud);
}

Log::~Log()
{
}

void Log::message(String pin)
{
    Serial.println("MSG:" + pin);
}

void Log::error(String pin)
{
    Serial.println("ERR:" + pin);
}