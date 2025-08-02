#ifndef INC_CONFIG_HPP_
#define INC_CONFIG_HPP_

#include <Arduino.h>
#include <ESP32Servo.h>

// Define Pins
#define BUZZER_PIN 10
#define LID_SERVO_PIN 27
#define SORTER_SERVO_PIN 12
#define ULT_PROXIMITY_SENSOR_TRIG_PIN 32
#define ULT_PROXIMITY_SENSOR_ECHO_PIN 33
#define ULT_FILL_MONITOR_TRIG_PIN 15
#define ULT_FILL_MONITOR_ECHO_PIN 16

// Define Constants
#define TRASH_FULL_LEVEL 2 // 2cm
#define SPEED_OF_SOUND_CM 0.034
#define DIST_TO_OPEN_LID 10
#define LID_SERVO_ORIGINAL_POS 0
#define LID_SERVO_FINAL_POS 90


#endif