#include <Arduino.h>
//#include "task/WaterPump.h"
#include "ReactiveArduinoLib.h"

using namespace Reactive;

//WaterPump waterPump;

/*const int pin12 = 11;

auto reactiveInput = Reactive::FromDigitalInput(pin12, INPUT_PULLUP);

auto observableIntSerialOutput = Reactive::Property<int>();

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    delay(1);

  //pinMode(LED_BUILTIN, OUTPUT);

  observableIntSerialOutput.ToSerial();

  reactiveInput
      .If([](int x) { return x== 1; },
          [](int x) { Serial.println(10 * x); })
      .DoNothing();
}

void loop()
{
  reactiveInput.Next();
}*/

auto reactiveInput = Reactive::FromDigitalInput(10, INPUT_PULLUP);

auto observableManual = Reactive::ManualDefer<int>();

bool isNotified;
bool isNotified2;

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    delay(1);

  observableManual
      .Toggle()
      .ToDigitalOutput(LED_BUILTIN);

  //observableManual.Next();

  reactiveInput
      .If([](int x) { return x == HIGH; },
          [](int x) {
            if (!isNotified)
            {
              Serial.println("La pompa è accesa");
              isNotified = true;
              isNotified2 = false;
              observableManual.Next();
            }
          })
      .If([](int x) { return x == LOW; },
          [](int x) {
            if (!isNotified2)
            {
              Serial.println("La pompa è spenta");
              isNotified = false;
              isNotified2 = true;
              observableManual.Next();
            }
          })
      .DoNothing();
}

void loop()
{
  reactiveInput.Next();
}