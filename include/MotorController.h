#include "Motor.h"
#include "Config.h"

#ifndef MOTOR_CONTROLLER
#define MOTOR_CONTROLLER

class MotorController
{
    public:
        Motor right_motor;
        Motor left_motor;
        void moveForward();
        void turnRight();
        void turnLeft();
        void regulate(int);
};

void MotorController::moveForward()
{
    right_motor.setSpeed(MOTOR_SPEED);
    left_motor.setSpeed(MOTOR_SPEED);
}

void MotorController::turnRight()
{
    right_motor.setSpeed(-MOTOR_SPEED);
    left_motor.setSpeed(MOTOR_SPEED);
}

void MotorController::turnLeft()
{
    right_motor.setSpeed(MOTOR_SPEED);
    left_motor.setSpeed(-MOTOR_SPEED);
}

void MotorController::regulate(int pid)
{
    right_motor.setSpeed(MOTOR_SPEED - pid);
    left_motor.setSpeed(MOTOR_SPEED + pid);
}

#endif