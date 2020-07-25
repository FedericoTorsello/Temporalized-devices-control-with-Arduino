#include <Arduino.h>
//#include "task/WaterPump.h"
#include "ReactiveArduinoLib.h"

using namespace Reactive;

//WaterPump waterPump;

int incomingByte = 0; // for incoming serial data

const int pin13 = LED_BUILTIN;
const int pin12 = 12;

/*
void setup()
{
  pinMode(pin13, OUTPUT);
  digitalWrite(pin13, LOW);

  pinMode(pin12, INPUT);
  digitalWrite(pin12, LOW);

  Serial.begin(9600);

  while (!Serial) delay(1); // wait for serial port to connect. Needed for native USB

  Serial.print("Start");
  
}
*/
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