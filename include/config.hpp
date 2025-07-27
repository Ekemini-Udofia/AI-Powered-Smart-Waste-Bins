#ifndef INC_CONFIG_HPP_
#define INC_CONFIG_HPP_

#include <Arduino.h>

// Define Pins
#define BUZZER_PIN 10
#define LID_SERVO_PIN 11
#define SORTER_SERVO_PIN 12
#define ULT_PROXIMITY_SENSOR_TRIG_PIN 13
#define ULT_PROXIMITY_SENSOR_ECHO_PIN 14
#define ULT_FILL_MONITOR_TRIG_PIN 15
#define ULT_FILL_MONITOR_ECHO_PIN 16

// Define Constants
#define TRASH_FULL_LEVEL 2 // 2cm
#define SPEED_OF_SOUND_CM 0.034
#define DIST_TO_OPEN_LID 10


#endif