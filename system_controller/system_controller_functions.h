#ifndef SYSTEM_CONTROLLER_FUNCTIONS
#define SYSTEM_CONTROLLER_FUNCTIONS

#include "system_controller_settings.h"


/* 
 * Set the "RGB" LED color by adjusting the "brightness" of each 
 * individual R, G, and B LEDs.
 */
void setLEDColor(LEDColor color) {  
    analogWrite(  RED_LED, color.redPWM  );
    analogWrite(GREEN_LED, color.greenPWM);
    analogWrite( BLUE_LED, color.bluePWM );
}

/* This version can be used for testing purposes. */
void setLEDColor(int redPWM, int greenPWM, int bluePWM) {
    analogWrite(  RED_LED, redPWM  );
    analogWrite(GREEN_LED, greenPWM);
    analogWrite( BLUE_LED, bluePWM );
}


#endif //SYSTEM_CONTROLLER_FUNCTIONS
