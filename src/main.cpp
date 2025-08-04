// Project Headers
#include "FillLevelMonitor.hpp"
#include "ProximityLidController.hpp"
#include "SmartSortEngine.hpp"
#include "config.hpp"
#include "DisplayModule.hpp"

void setup() {
  DMInit();
  PLCInit();
  // sorter.begin();
  binFull();
  FLMInit();
  Serial.begin(115200);

}

void loop() {
  senseProximity();
}