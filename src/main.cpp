#include <Arduino.h>

const uint8_t pin2 = 2;
const uint8_t pin4 = 4;
const uint8_t pin7 = 7;
const uint8_t pin8 = 8;
const uint8_t pin12 = 12;

const long period = 1000; // period at which to blink in ms

unsigned long previousMillis; //will store last time LED was blinked
unsigned long currentMillis;

bool ledState;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  pinMode(pin2, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin12, OUTPUT);
}

void generalTask(void (*f)())
{
  currentMillis = millis(); // store the current time
  if (currentMillis - previousMillis >= period)
  {
    previousMillis = currentMillis; // save the last time you blinked the LED
    ledState = !ledState;

    f();
  }
}

void task()
{
  generalTask([] {
    digitalWrite(LED_BUILTIN, ledState);
  });
}

void loop()
{
  task();
}
