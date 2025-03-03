#include <Arduino.h>
#include "encoder.h"

void setup() {
    Serial.begin(115200);

    // Configure encoder pins as inputs with pull-up resistors
    pinMode(ENCODER_A_PIN, INPUT_PULLUP);
    pinMode(ENCODER_B_PIN, INPUT_PULLUP);

    // Attach an interrupt to count pulses on the rising edge of the A signal
    attachInterrupt(digitalPinToInterrupt(ENCODER_A_PIN), ISR_Encoder, RISING);
}

void loop() {
    uint32_t currentMillis = millis();

    if (currentMillis - lastMillis >= 1000) {
        noInterrupts();  // Disable interrupts to safely access pulseCount
        int32_t pulsesPerSecond = pulseCount;
        pulseCount = 0;
        interrupts();    // Re-enable interrupts

        if (pulsesPerSecond != 0) {
            encoderMoving = true;
            String direction = (pulsesPerSecond > 0) ? "Forward" : "Reverse";
            float encoderRPM = (abs(pulsesPerSecond) * 60.0) / encoderPPR;
            float chainSpeedInchesPerMin = encoderRPM * rollerCircumference;
            float chainSpeedFeetPerMin = chainSpeedInchesPerMin / 12.0;

            Serial.print("Encoder Frequency: ");
            Serial.print(abs(pulsesPerSecond));
            Serial.println(" Hz");

            Serial.print("Encoder RPM: ");
            Serial.print(encoderRPM);
            Serial.println(" RPM");

            Serial.print("Direction: ");
            Serial.println(direction);

            Serial.print("Chain Speed: ");
            Serial.print(chainSpeedInchesPerMin);
            Serial.print(" inches/min, ");
            Serial.print(chainSpeedFeetPerMin);
            Serial.println(" feet/min");

            Serial.println();
        } 
        else if (encoderMoving) {
            Serial.println("Encoder Stopped.");
            encoderMoving = false;
        }

        lastMillis = currentMillis;
    }
}
