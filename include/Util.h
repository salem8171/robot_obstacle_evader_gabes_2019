#include "Arduino.h"

#ifndef UTIL
#define UTIL

#define pmo(pin) pinMode(pin, OUTPUT)
#define pmi(pin) pinMode(pin, INPUT)

#define dwh(pin) digitalWrite(pin, HIGH);
#define dwl(pin) digitalWrite(pin, LOW);

#define aw analogWrite

#endif