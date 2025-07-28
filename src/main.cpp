// Project Headers
#include "FillLevelMonitor.hpp"
#include "ProximityLidController.hpp"
#include "SmartSortEngine.hpp"
#include "config.hpp"

void setup() {
  PLCInit();
  // sorter.begin();
  binFull();
  FLMInit();
  Serial.begin(119500);

}

void loop() {
  senseProximity();
}