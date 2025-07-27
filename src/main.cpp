#include <Arduino.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>

// Project Headers
#include "FillLevelMonitor.hpp"
#include "ProximityLidController.hpp"
#include "SmartSortEngine.hpp"


void setup() {
  // lid.begin();
  // sorter.begin();
  binInit();
  Serial.begin(119500);

}

void loop() {
  // lid.update();
  // if (lid.lidJustClosed()) {
    // sorter.processWaste();
    // binLevel.checkLevel();
  // }
}

// tone(buzzer, 500); if(binFull)
// noTone(buzzer);