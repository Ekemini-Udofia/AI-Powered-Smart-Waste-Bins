#include "config.hpp"
#include "FillLevelMonitor.hpp"
#include "SmartSortEngine.hpp"

void PLCInit() {
    pinMode(ULT_PROXIMITY_SENSOR_ECHO_PIN, INPUT);
    pinMode(ULT_PROXIMITY_SENSOR_TRIG_PIN, OUTPUT);
    pinMode(LID_SERVO_PIN, OUTPUT);
    pinMode(BUZZER_PIN, OUTPUT);

    ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
    lidServo.attach(LID_SERVO_PIN, 500, 2400);
    lidServo.setPeriodHertz(50);
}

static void openLid(){
    lidServo.write(LID_SERVO_ORIGINAL_POS);
    delay(10); // Change this to make the bin open for longer
    lidServo.write(LID_SERVO_FINAL_POS);
}
void senseProximity() { // Checks if someone is close and opens the lid
    // Use ULT Sensor to check the readings of ultrasonic sensor
    // Use an If condition to trigger the SmartSortEngine
    // This function will be called in void loop(), so it will run repeatedly

    digitalWrite(ULT_PROXIMITY_SENSOR_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(ULT_PROXIMITY_SENSOR_TRIG_PIN, HIGH);
    delayMicroseconds(10); 
    digitalWrite(ULT_PROXIMITY_SENSOR_TRIG_PIN, LOW);

    float timer = pulseIn(ULT_PROXIMITY_SENSOR_ECHO_PIN, HIGH);
    float humanProximity = (timer * SPEED_OF_SOUND_CM) / 2;

    if(humanProximity <= DIST_TO_OPEN_LID) {
        if(binFull) {
            // Beep Twice and don't open
            tone(BUZZER_PIN, 500);
            delay(500);
            noTone(BUZZER_PIN);
            delay(500);
            tone(BUZZER_PIN, 500);
            delay(500);
            noTone(BUZZER_PIN);
        } else {
            // Open Lid and Close after 10 Seconds
            openLid();
            Serial.println("Lid Opened"); // For debugging. Delete Later
            // Call SmartSortEngine
            SSETrigger();
        }
    } 
}