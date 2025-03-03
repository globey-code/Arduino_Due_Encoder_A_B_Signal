#ifndef encoder_h
#define encoder_h

#include <Arduino.h>

// Pin definitions for the encoder
#define ENCODER_A_PIN 2  // Encoder A signal input on Pin 2
#define ENCODER_B_PIN 3  // Encoder B signal input on Pin 3

// Global variables (declared as extern so they can be defined in a source file)
extern volatile int32_t pulseCount;
extern uint32_t lastMillis;
extern bool encoderMoving;

// Constants for the encoder calculations
const int encoderPPR = 3600;                  // Encoder resolution (Pulses Per Revolution)
const float rollerDiameterInches = 5.0;         // Change based on actual roller size
const float rollerCircumference = 3.14159 * rollerDiameterInches;  // π * D

// Function prototype for the interrupt service routine
void ISR_Encoder();

#endif // ENCODER_H
