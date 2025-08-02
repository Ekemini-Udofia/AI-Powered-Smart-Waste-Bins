#include <unity.h>
#include <Arduino.h>
#include "ProximityLidController.hpp"
#include "config.hpp"

void setUp(void) {
    // Set up stuff here
}

void tearDown(void) {
    // Clean up stuff here
}

void testOpenLid() {
    PLCInit();
    TEST_ASSERT_EQUAL(0, digitalRead(BUZZER_PIN));
}

int main(int argc, char**argv) {
    UNITY_BEGIN();
    RUN_TEST(testOpenLid);
    return UNITY_END();
}