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
    String testInput = "";
    if (Serial.available()>0){
        testInput = Serial.readString();
        Serial.println(testInput);
    }

    // Testing code for PWM
    if (testInput == "Really Soft\n") {
      setLEDColor(CYAN);
    } else if (testInput == "Soft\n") {
      setLEDColor(PURPLE);
    } else if (testInput == "Medium\n") {
      setLEDColor(GREEN);
    } else if (testInput == "Loud\n") {
      setLEDColor(ORANGE);
    } else if (testInput == "Really Loud\n") {
      setLEDColor(RED);
    } else {
      setLEDColor(0, 0, 0);
    }

    // Delay for testing that color is displayed
    delay(2000);
}
