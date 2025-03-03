#include <Arduino.h>
#include "encoder.h"

// Define the global variables declared in the header
volatile int32_t pulseCount = 0;
uint32_t lastMillis = 0;
bool encoderMoving = false;

void ISR_Encoder() {
    if (digitalRead(ENCODER_B_PIN) == HIGH) {
        pulseCount++;  // Clockwise rotation
    } else {
        pulseCount--;  // Counterclockwise rotation
    }
}
