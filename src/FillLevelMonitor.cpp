#include <Arduino.h>
#include "config.hpp"

//If Ultrasonic Sensor reads less than TRASH_FULL_LEVEL, do a loop to beep a buzzer on lid open

void binInit()
{
    pinMode(ULT_FILL_MONITOR_ECHO_PIN, INPUT);
    pinMode(ULT_FILL_MONITOR_TRIG_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);
}

bool binFull(){
    digitalWrite(ULT_FILL_MONITOR_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(ULT_FILL_MONITOR_TRIG_PIN, HIGH);
    delayMicroseconds(10); // Change this
    digitalWrite(ULT_FILL_MONITOR_TRIG_PIN, LOW);

    float timer = pulseIn(ULT_FILL_MONITOR_ECHO_PIN, HIGH);

    int trashLevel = (timer * SPEED_OF_SOUND_CM) / 2; //Replace with Speed of Sound Constant

    return trashLevel <= TRASH_FULL_LEVEL; // Causing the Buzzer to or to not beep at startup
}


