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
    for (int i=0; i<NUM_LEDS; ++i) {
        // Initialize output pins for PWM
        pinMode(  RED_LED[i], OUTPUT);
        pinMode(GREEN_LED[i], OUTPUT);
        pinMode( BLUE_LED[i], OUTPUT);

        // Set output pins to be off initially
        analogWrite(  RED_LED[i], convertPWM(0));
        analogWrite(GREEN_LED[i], convertPWM(0));
        analogWrite( BLUE_LED[i], convertPWM(0));
    }
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
      setLEDColor(255, 255, 255);
    }
}
