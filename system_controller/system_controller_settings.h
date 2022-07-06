#ifndef SYSTEM_CONTROLLER_SETTINGS_H
#define SYSTEM_CONTROLLER_SETTINGS_H

#include "system_controller_defined_types.h"


// Number of RGB LED Pairs
const int NUM_LEDS = 2;

// Pins 
int   RED_LED[] = {3,  9};
int GREEN_LED[] = {5, 10};
int  BLUE_LED[] = {6, 11};

// LED colors to change to
const int   Cyan = 0;
const int Purple = 1;
const int  Green = 2;
const int Orange = 3;
const int    Red = 4;
const int    Off = 5;

// LED color PWM values (  R,   G,   B)
const LEDColor   CYAN = {  0, 255, 255};
const LEDColor PURPLE = {128,   0, 128};
const LEDColor  GREEN = {  0, 255,   0};
const LEDColor ORANGE = {255, 165,   0};
const LEDColor    RED = {255,   0,   0}; 
const LEDColor    OFF = {  0,   0,   0};


#endif //SYSTEM_CONTROLLER_SETTINGS_H