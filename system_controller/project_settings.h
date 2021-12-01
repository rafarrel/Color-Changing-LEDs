#ifndef PROJECT_SETTINGS_H
#define PROJECT_SETTINGS_H

#include "defined_types.h"

// Pins (change placeholder values)
const int   RED_LED = 3;
const int GREEN_LED = 5;
const int  BLUE_LED = 6;

// LED Colors           (  R,   G,   B)
const LEDColor CYAN   = {  0, 255, 255};
const LEDColor PURPLE = {128,   0, 128};

/**************************************************************/

void setLEDColor(const LEDColor color) {  
  //analogWrite(  RED_LED, 0);
  //analogWrite(GREEN_LED, 0);
  //analogWrite( BLUE_LED, 64);
}

#endif //PROJECT_SETTINGS_H