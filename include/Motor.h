#include "Util.h"

#ifndef MOTOR
#define MOTOR

class Motor
{
    private:
        int pin1;
        int pin2;
        int speedPin;
        
    public:
        void setup(int, int, int);
        void setSpeed(int speed);
};

void Motor::setup(int pin1, int pin2, int speedPin)
{
    this -> pin1 = pin1;
    this -> pin2 = pin2;
    this -> speedPin = speedPin;

    pmo(pin1);
    pmo(pin2);
    pmo(speedPin);
}

void Motor::setSpeed(int speed)
{
    if (speed >= 0)
    {  
        dwh(pin1);
        dwl(pin2);
        aw(speedPin, speed < 255 ? speed : 255);
    }
    else 
    {
        dwl(pin1);
        dwh(pin2);
        aw(speedPin, -speed < 255 ? -speed : 255);
    }
}

#endif