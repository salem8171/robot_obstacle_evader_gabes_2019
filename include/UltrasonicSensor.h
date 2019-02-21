#include "Util.h"
#include "Config.h"

#ifndef ULTRASONIC_SENSOR
#define ULTRASONIC_SENSOR

class UltrasonicSensor
{
    private:
        int trig_pin;
        int echo_pin;
    
    public:
        void setup(int, int);
        int getDistance();
};

void UltrasonicSensor::setup(int trig_pin, int echo_pin)
{
    this -> trig_pin = trig_pin;
    this -> echo_pin = echo_pin;
}

int UltrasonicSensor::getDistance()
{
    pmo(trig_pin);
    dwl(trig_pin); delay(2);
    dwh(trig_pin); delay(5);
    dwl(trig_pin);

    pmi(echo_pin);
    int distance = pulseIn(echo_pin, HIGH, PULSE_TIMEOUT) / 58;

    return (distance > 2) ? distance : MAX_DISTANCE;
}

#endif