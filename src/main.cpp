#include <Arduino.h>
#include "./task/WaterPump.hpp"
#include "./task/Log.hpp"
#include "./task/Time.hpp"

typedef struct
{
    String value;
    WaterPump *waterPump;
} componentDictionary;

const componentDictionary componentArray[]{
    {"ID-01", new WaterPump("ID-01", LED_BUILTIN, Time::second(5), Time::second((10)))},
    {"ID-02", new WaterPump("ID-02", 14, Time::second(5), Time::second((10)))}};

void setup()
{
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
