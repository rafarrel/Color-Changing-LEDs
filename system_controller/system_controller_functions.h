#ifndef SYSTEM_CONTROLLER_FUNCTIONS
#define SYSTEM_CONTROLLER_FUNCTIONS

#include "system_controller_settings.h"


/* 
 * Convert given PWM value to be inverted if the voltage input
 * for the hardware is inverted.
 */
int convertPWM(int invertedPWM) {
    return 255 - invertedPWM;
}

/* 
 * Set the "RGB" LED color by adjusting the "brightness" of each 
 * individual R, G, and B LEDs.
 */
void setLEDColor(LEDColor color) { 
    // Inverted TESTING
    for (int i=0; i<NUM_LEDS; ++i) {
        analogWrite(  RED_LED[i], convertPWM(color.redPWM)  );
        analogWrite(GREEN_LED[i], convertPWM(color.greenPWM));
        analogWrite( BLUE_LED[i], convertPWM(color.bluePWM) );
    }
}

/* 
 * This version can be used for testing purposes. 
 */
void setLEDColor(int redPWM, int greenPWM, int bluePWM) {
    // Inverted TESTING
    for (int i=0; i<NUM_LEDS; ++i) {
        analogWrite(  RED_LED[i], convertPWM(redPWM)  );
        analogWrite(GREEN_LED[i], convertPWM(greenPWM));
        analogWrite( BLUE_LED[i], convertPWM(bluePWM) );
    }
}


#endif //SYSTEM_CONTROLLER_FUNCTIONS
