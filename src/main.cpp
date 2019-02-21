#include <Arduino.h>
#include "UltrasonicSensor.h"
#include "MotorController.h"

UltrasonicSensor right_sensor;
UltrasonicSensor middle_sensor;
UltrasonicSensor left_sensor;

MotorController motor_controller;

void setup()
{
    right_sensor.setup(RIGHT_ULTRASONIC_TRIG_PIN, RIGHT_ULTRASONIC_ECHO_PIN);
    middle_sensor.setup(MIDDLE_ULTRASONIC_TRIG_PIN, MIDDLE_ULTRASONIC_ECHO_PIN);
    left_sensor.setup(LEFT_ULTRASONIC_TRIG_PIN, LEFT_ULTRASONIC_ECHO_PIN);

    motor_controller.right_motor.setup(RIGHT_MOTOR_PIN1, RIGHT_MOTOR_PIN2, RIGHT_MOTOR_SPEED_PIN);
    motor_controller.left_motor.setup(LEFT_MOTOR_PIN1, LEFT_MOTOR_PIN2, LEFT_MOTOR_SPEED_PIN);

    motor_controller.moveForward();
}

void loop()
{
    int right_distance = right_sensor.getDistance();
    int left_distance = left_sensor.getDistance();
    int middle_distance = middle_sensor.getDistance();

    if (right_distance + left_distance < CORRIDOR_WIDTH)
    // Inside a corridor: regulate distances
    {
        int pid = KP * (right_distance - left_distance);
        motor_controller.regulate(pid);
        return;
    }

    // TODO: right distance > long distance and left distance > long distance
    // if (right_distance > LONG_DISTANCE && left_distance > LONG_DISTANCE)
    // {

    //     return;
    // }

    if (right_distance > LONG_DISTANCE)
    // Right turn
    {
        if (middle_distance < MINIMUM_FRONTAL_DISTANCE);
        // Frontal wall too close: turn rapidly
        {
            motor_controller.turnRight();
            return;
        }

        // Regulate left distance
        int pid = KP * (ONE_SIDED_REGULATION_DISTANCE - left_distance);
        motor_controller.regulate(pid);
        return;
    }

    if (left_distance > LONG_DISTANCE)
    // Left turn
    {
        if (middle_distance < MINIMUM_FRONTAL_DISTANCE);
        // Frontal wall too close: turn rapidly
        {
            motor_controller.turnLeft();
            return;
        }

        // Regulate right distance
        int pid = KP * (right_distance - ONE_SIDED_REGULATION_DISTANCE);
        motor_controller.regulate(pid);
        return;
    }  
}