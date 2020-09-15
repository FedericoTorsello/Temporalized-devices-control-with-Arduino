#include <Arduino.h>
#include "./task/WaterPump.hpp"
#include "./task/Log.hpp"

const uint8_t WATER_PUMP1 = 2;
const uint8_t WATER_PUMP2 = 4;
const uint8_t WATER_PUMP3 = 7;

const unsigned long SECOND = 1000UL;
const unsigned long MINUTE = 60UL * SECOND;
const unsigned long HOUR = 3600UL * SECOND;

//https://github.com/gadgetstogrow/TaskScheduler/blob/024aa49f1e/TaskSched/TaskScheduler.h

auto h = [](uint8_t x) { return x * HOUR; };
auto m = [](uint8_t x) { return x * MINUTE; };
auto s = [](uint8_t x) { return x * SECOND; };

WaterPump waterPumpArray[] = {
    WaterPump(LED_BUILTIN, s(2), s(10)),
    WaterPump(LED_BUILTIN, s(10), s(60)),
    WaterPump(LED_BUILTIN, s(20), s(30))};

unsigned long matrice[][5] = {
    //WHO - start - WHEN_START - DURATION - CURRENT MILLIS
    {LED_BUILTIN, true, s(1), s(10), 0},
    {WATER_PUMP1, true, h(20), m(2), 0}, //pin2
    {WATER_PUMP2, true, h(22), m(2), 0}, //pin4
    {WATER_PUMP3, true, h(24), m(2), 0}  //pin7
};

uint8_t nColums = sizeof(matrice) / sizeof(matrice[0]);

void setup()
{
    Log(9600);
    Log::message("ciao");

    for(auto &i : waterPumpArray){
        i.switchOff();
        delay(1000);
        i.switchOn();
        delay(1000);
    }

    /*for (auto &&i : matrice)
    {
        uint8_t currentPin = i[0];
        bool isTurnOn = (bool)i[1];
        pinMode(currentPin, OUTPUT);
        digitalWrite(currentPin, isTurnOn);
    }*/
}

void myTask(unsigned long &previousMillis, bool &isTurnOn, uint8_t currentPin, unsigned long whenStart, unsigned long duration)
{

    unsigned long currentMillis = millis();
    if ((isTurnOn == HIGH) && (currentMillis - previousMillis >= whenStart))
    {
        Serial.println("============");
        Serial.print(F("| TURN OFF\t"));
        Serial.println(currentPin);
        Serial.print(F("| WhenStart:\t"));
        Serial.println(whenStart);
        Serial.println("============\n");

        isTurnOn = LOW;                     // Turn it off
        previousMillis = currentMillis;     // Remember the time
        digitalWrite(currentPin, isTurnOn); // Update the actual LED
    }
    else if ((isTurnOn == LOW) && (currentMillis - previousMillis >= duration))
    {
        Serial.println("&&&&&&&&&&&");
        Serial.print(F("| TURN ON\t"));
        Serial.println(currentPin);
        Serial.print(F("| Duration:\t"));
        Serial.println(duration);
        Serial.println("&&&&&&&&&&&\n");

        isTurnOn = HIGH;                    // turn it on
        previousMillis = currentMillis;     // Remember the time
        digitalWrite(currentPin, isTurnOn); // Update the actual LED
    }
}

void loop()
{
    /*for (auto &&i : matrice)
    {
        uint8_t currentPin = i[0];
        bool isTurnOn = (bool)i[1];
        unsigned long whenStart = i[2];
        unsigned long duration = i[3];
        unsigned long previousMillis = i[4];

        myTask(previousMillis, isTurnOn, currentPin, whenStart, duration);
        i[1] = isTurnOn;
        i[4] = previousMillis;
    }*/
}
