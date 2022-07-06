/* 
 * Embedded Programming C Final Project: 
 *    Audio-reactive color changing LEDs
 * 
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
    // Receive input from computer audio controller.
    int colorToSet = -1;
    if (Serial.available()>0){
        colorToSet = Serial.parseInt();
    }

    // Set LED colors based on received input from the 
    // computer audio controller.
    if (colorToSet == Cyan) {
      setLEDColor(CYAN);
    } else if (colorToSet == Purple) {
      setLEDColor(PURPLE);
    } else if (colorToSet == Green) {
      setLEDColor(GREEN);
    } else if (colorToSet == Orange) {
      setLEDColor(ORANGE);
    } else if (colorToSet == Red) {
      setLEDColor(RED);
    } else if (colorToSet == Off) {
      setLEDColor(OFF);
    }
}