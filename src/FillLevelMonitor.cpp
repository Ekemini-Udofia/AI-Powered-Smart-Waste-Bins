#include <Arduino.h>
#include "config.hpp"

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
    delayMicroseconds(10); 
    digitalWrite(ULT_FILL_MONITOR_TRIG_PIN, LOW);

    float timer = pulseIn(ULT_FILL_MONITOR_ECHO_PIN, HIGH);

    int trashLevel = (timer * SPEED_OF_SOUND_CM) / 2; 

    return trashLevel <= TRASH_FULL_LEVEL;
}


