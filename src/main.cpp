#include <Arduino.h>

/*
const uint8_t pin2 = 2;
const uint8_t pin4 = 4;
const uint8_t pin7 = 7;
const uint8_t pin8 = 8;
const uint8_t pin12 = 12;
*/

const uint8_t WATER_PUMP1 = 2;
const uint8_t WATER_PUMP2 = 4;
const uint8_t WATER_PUMP3 = 7;

const unsigned long SECOND = 1000UL;
const unsigned long MINUTE = 60UL * SECOND;
const unsigned long HOUR = 3600UL * SECOND;

//https://github.com/gadgetstogrow/TaskScheduler/blob/024aa49f1e/TaskSched/TaskScheduler.h

auto h = [](uint8_t x) { return x * HOUR; };
auto m = [](uint8_t x) { return x * MINUTE; };

unsigned long matrice[][5] ={
    //WHO - start - WHEN_START - DURATIO- CURRENT MILLIS
    //{ LED_BUILTIN, 0, 2000, 3000, 0 },
    { WATER_PUMP1, false, 6000, 6000, 0 }, //pin2
    { WATER_PUMP2, false, 3000, 6000, 0 }, //pin4
    { WATER_PUMP3, false, 4000, 6000, 0 } //pin7
};

uint8_t nColums = sizeof(matrice)/sizeof(matrice[0]);

void setup()
{
    Serial.begin(9600);
    while (!Serial);

    for (auto &&i : matrice)
    {
        uint8_t currentPin = i[0];
        bool isTurnOn = (bool)i[1];
        pinMode(currentPin, OUTPUT);
        digitalWrite(currentPin, isTurnOn);
    }
}

void myTask(unsigned long &previousMillis, bool &isTurnOn, uint8_t currentPin, unsigned long whenStart, unsigned long duration) {

    unsigned long currentMillis = millis();
    if (isTurnOn && (currentMillis - previousMillis >= whenStart))
    {
        Serial.println("============");
        Serial.print(F("| TURN OFF\t"));
        Serial.println(currentPin);

        Serial.print(F("| WhenStart:\t"));
        //Serial.print(whenStart/HOUR);
        //Serial.print(F(" Hours\t"));
        Serial.println(whenStart);
        Serial.println("============\n");

        isTurnOn = LOW;  // Turn it off
        previousMillis = currentMillis;  // Remember the time
        digitalWrite(currentPin, isTurnOn);  // Update the actual LED
    }
    else if (!isTurnOn && (currentMillis - previousMillis >= duration))
    {
        Serial.println("&&&&&&&&&&&");
        Serial.print(F("| TURN ON\t"));
        Serial.println(currentPin);
        Serial.print(F("| Duration:\t"));
        //Serial.print(duration/MINUTE);
        //Serial.print(F(" Minutes\n"));
        Serial.println(duration);
        Serial.println("&&&&&&&&&&&\n");

        isTurnOn = HIGH;  // turn it on
        previousMillis = currentMillis;   // Remember the time
        digitalWrite(currentPin, isTurnOn);	  // Update the actual LED
    }
}

void loop()
{
    for (auto &&i : matrice)
    {
        uint8_t currentPin = i[0];
        bool isTurnOn = (bool)i[1];
        unsigned long whenStart = i[2];
        unsigned long duration = i[3];
        unsigned long previousMillis = i[4];

        myTask(previousMillis, isTurnOn, currentPin, whenStart, duration);
        i[1] = isTurnOn;
        i[4] = previousMillis;
    }
}
