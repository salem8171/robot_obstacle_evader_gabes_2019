#ifndef CONFIG
#define CONFIG

#define RIGHT_MOTOR_PIN1 2
#define RIGHT_MOTOR_PIN2 4
#define RIGHT_MOTOR_SPEED_PIN 3

#define LEFT_MOTOR_PIN1 5
#define LEFT_MOTOR_PIN2 7
#define LEFT_MOTOR_SPEED_PIN 6

#define MOTOR_SPEED 150

#define KP 1

#define RIGHT_ULTRASONIC_TRIG_PIN 8
#define RIGHT_ULTRASONIC_ECHO_PIN 9

#define MIDDLE_ULTRASONIC_TRIG_PIN 10
#define MIDDLE_ULTRASONIC_ECHO_PIN 11

#define LEFT_ULTRASONIC_TRIG_PIN 12
#define LEFT_ULTRASONIC_ECHO_PIN 13

#define MAX_DISTANCE 40
#define PULSE_TIMEOUT (MAX_DISTANCE * 58)

#define CORRIDOR_WIDTH 25
#define LONG_DISTANCE 15
#define ONE_SIDED_REGULATION_DISTANCE 7
#define MINIMUM_FRONTAL_DISTANCE 7

#endif