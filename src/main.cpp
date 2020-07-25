#include <Arduino.h>
//#include "task/WaterPump.h"
#include "ReactiveArduinoLib.h"

using namespace Reactive;

//WaterPump waterPump;

const int pin12 = 12;

auto reactiveInput = Reactive::FromDigitalInput(pin12, INPUT_PULLUP);

auto observableInt = Reactive::Property<int>();

auto observableIntSerialOutput = Reactive::Property<int>();

void setup()
{
  Serial.begin(115200);
  while (!Serial)
    delay(1);

  observableIntSerialOutput.ToSerial();

  observableInt
      .Select([](int x) { return digitalRead(pin12); })
      .ToDigitalOutput(LED_BUILTIN);

  reactiveInput
      .If([](int x) { return x == HIGH; }, [](int x) { observableIntSerialOutput = x; })
      .DoNothing();
}

void loop()
{
  reactiveInput.Next();
}