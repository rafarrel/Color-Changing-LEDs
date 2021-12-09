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
    // Initialize serial port connection
    Serial.begin(9600);
    
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
    // Testing input from computer
    int testInput = -1;
    if (Serial.available()>0){
        testInput = Serial.parseInt();
    }

    // Testing code for PWM
    if (testInput == Cyan) {
      setLEDColor(CYAN);
    } else if (testInput == Purple) {
      setLEDColor(PURPLE);
    } else if (testInput == Green) {
      setLEDColor(GREEN);
    } else if (testInput == Orange) {
      setLEDColor(ORANGE);
    } else if (testInput == Red) {
      setLEDColor(RED);
    } else if (testInput == Off) {
      setLEDColor(OFF);
    }
}
