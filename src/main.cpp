#include <Arduino.h>
#include "./task/Device.hpp"
#include "./task/WaterPump.hpp"
#include "./task/Log.hpp"
#include "./task/Time.hpp"

typedef struct
{
    WaterPump *waterPump;
} componentDictionary;

const componentDictionary componentArray[]{
    new WaterPump("TEST", LED_BUILTIN, Time::second(1), Time::second(1), Time::second(10)),
    new WaterPump("RED-BLACK", 2, Time::hour(12), Time::second(30), Time::minute(1)),
    new WaterPump("YELLOW-GREEN", 4, Time::hour(12), Time::second(30), Time::minute(2)),
    new WaterPump("BLUE-WHITE", 7, Time::hour(12), Time::second(30), Time::minute(3))};

void setup()
{
    delay(1000);

    Log(9600);
    Log::message("SETUP PROGRAM");

    for (auto &i : componentArray)
    {
        auto component = i.waterPump;
        component->description();
    }
}

void loop()
{
    for (auto &i : componentArray)
    {
        auto current = i.waterPump;
        current->runTask();
    }
}
