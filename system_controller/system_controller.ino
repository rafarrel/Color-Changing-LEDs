/* 
 * TODO: MAKE BETTER HEADER
 *  
 * Embedded Programming C Final Project 
 * Alex Farrell, Maegan Beckage
 * 
 * Term legend:
 *    1) PWM -> Pulse Width Modulation
 */
#include "system_controller_functions.h"


void setup() {
    // Initialize output pins for PWM
    pinMode(  RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode( BLUE_LED, OUTPUT);

    // Set output pins to be off initially
    analogWrite(  RED_LED, 255);
    analogWrite(GREEN_LED, 255);
    analogWrite( BLUE_LED, 255);
}

void loop() {
    // Change color for testing
    Color testColor = TestC;

    // Testing code for PWM
    if (testColor == Cyan) {
      setLEDColor(CYAN);
    } else if (testColor == Purple) {
      setLEDColor(PURPLE);
    } else if (testColor == Green) {
      setLEDColor(GREEN);
    } else if (testColor == Orange) {
      setLEDColor(ORANGE);
    } else if (testColor == Red) {
      setLEDColor(RED);
    } else if (testColor == TestC) {
      setLEDColor(TEST_C);
    }
}
