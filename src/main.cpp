#include <Arduino.h>
#include "UltrasonicSensor.h"
#include "Motor.h"

UltrasonicSensor right_sensor;
UltrasonicSensor middle_sensor;
UltrasonicSensor left_sensor;

Motor right_motor;
Motor left_motor;

void setup()
{
    right_sensor.setup(RIGHT_ULTRASONIC_TRIG_PIN, RIGHT_ULTRASONIC_ECHO_PIN);
    middle_sensor.setup(MIDDLE_ULTRASONIC_TRIG_PIN, MIDDLE_ULTRASONIC_ECHO_PIN);
    left_sensor.setup(LEFT_ULTRASONIC_TRIG_PIN, LEFT_ULTRASONIC_ECHO_PIN);

    right_motor.setup(RIGHT_MOTOR_PIN1, RIGHT_MOTOR_PIN2, RIGHT_MOTOR_SPEED_PIN);
    left_motor.setup(LEFT_MOTOR_PIN1, LEFT_MOTOR_PIN2, LEFT_MOTOR_SPEED_PIN);

    right_motor.setSpeed(MOTOR_SPEED);
    left_motor.setSpeed(MOTOR_SPEED);
}

void loop()
{
    if (middle_sensor.getDistance() < 7)
    {
        right_motor.setSpeed(-MOTOR_SPEED);
        left_motor.setSpeed(-MOTOR_SPEED);
        return;
    }

    int error = right_sensor.getDistance() - left_sensor.getDistance();
    int pid = KP * error;

    right_motor.setSpeed(MOTOR_SPEED - pid);
    left_motor.setSpeed(MOTOR_SPEED + pid);
}