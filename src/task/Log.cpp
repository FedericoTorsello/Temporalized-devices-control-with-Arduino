#include "Log.hpp"

Log::Log(unsigned long baud)
{
    if (baud > 0)
        Serial.begin(baud);
    else
        Serial.begin(9600);
}

Log::~Log()
{
}

void Log::message(String msg, bool isFrameVisible)
{
    if (Serial.available())
    {
        Serial.print(msg);
        printFrame(isFrameVisible);
    }
}

void Log::printFrame(bool isFrameVisible)
{
    if (isFrameVisible)
    {
        Serial.print('\n');
        Serial.print(F("---.---.---.---.---"));
    }

    Serial.print("\n\n");
}

void Log::error(String msg, bool isFrameVisible)
{
    if (Serial.available())
    {
        printFrame(isFrameVisible);

        Serial.print("ERR: ");
        Serial.print(msg);
        Serial.print('\n');

        printFrame(isFrameVisible);
    }
}