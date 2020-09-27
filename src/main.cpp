#include <Arduino.h>
#include "./task/WaterPump.hpp"
#include "./task/Log.hpp"
#include "./task/Time.hpp"

typedef struct
{
    WaterPump *waterPump;
} componentDictionary;

const componentDictionary componentArray[]{
    {new WaterPump("ID-01", LED_BUILTIN, Time::second(5), Time::second(10))},
    {new WaterPump("ID-02", 2, Time::second(2), Time::second(10))},
    {new WaterPump("ID-03", 4, Time::second(2), Time::second(10))},
    {new WaterPump("ID-04", 7, Time::second(2), Time::second(10))}};

void setup()
{
    Log(115200);
    //Log::isEnabled(false);
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
