/* 
 * TODO: MAKE BETTER HEADER
 *  
 * Embedded Programming C Final Project 
 * Alex Farrell, Maegan Beckage
 * 
 * Term legend:
 *    1) PWM -> Pulse Width Modulation
 */
#include "project_settings.h"


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
  // Testing code for PWM
  Color test = Purple;  // Change color for testing
  
  if (test == Cyan) {
    //setLEDColor(CYAN);
  } else if (test == Purple) {
    //setLEDColor(PURPLE);
  }
}
