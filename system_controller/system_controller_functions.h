#ifndef SYSTEM_CONTROLLER_FUNCTIONS
#define SYSTEM_CONTROLLER_FUNCTIONS

#include "system_controller_settings.h"
/**************************************************************/

/* 
 * Set the "RGB" LED color by adjusting the "brightness" of each 
 * individual R, G, and B LEDs.
 */
void setLEDColor(LEDColor color) {  
    analogWrite(  RED_LED, color.redPWM  );
    analogWrite(GREEN_LED, color.greenPWM);
    analogWrite( BLUE_LED, color.bluePWM );
}

/**************************************************************/
#endif //SYSTEM_CONTROLLER_FUNCTIONS
