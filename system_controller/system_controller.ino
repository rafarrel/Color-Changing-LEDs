/* 
 * TODO: MAKE BETTER HEADER
 *  
 * Embedded Programming C Final Project 
 * Alex Farrell, Maegan Beckage
 * 
 * Term legend:
 *    1) PWM -> Pulse Width Modulation
 */

/**************************************************************/

// Pins (change placeholder values)
const int RED   = 0;
const int GREEN = 1;
const int BLUE  = 2;

/**************************************************************/
void setup() {
  // Initialize output pins for PWM
  pinMode(RED  , OUTPUT)
  pinMode(GREEN, OUTPUT)
  pinMode(BLUE , OUTPUT)
}

void loop() {
  // Testing code for PWM
  //          LED  , "Brightness"
  analogWrite(RED  , 32 );
  analogWrite(GREEN, 78 );
  analogWrite(BLUE , 105);
}
