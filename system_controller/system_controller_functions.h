#ifndef SYSTEM_CONTROLLER_FUNCTIONS
#define SYSTEM_CONTROLLER_FUNCTIONS

#include "system_controller_settings.h"


/* 
 * Set the "RGB" LED color by adjusting the "brightness" of each 
 * individual R, G, and B LEDs.
 */
void setLEDColor(LEDColor color) { 
    // Inverted TESTING
    for (int i=0; i<NUM_LEDS; ++i) {
        analogWrite(  RED_LED[i], 255 - color.redPWM  );
        analogWrite(GREEN_LED[i], 255 - color.greenPWM);
        analogWrite( BLUE_LED[i], 255 - color.bluePWM );
    }
}

/* This version can be used for testing purposes. */
void setLEDColor(int redPWM, int greenPWM, int bluePWM) {
    // Inverted TESTING
    for (int i=0; i<NUM_LEDS; ++i) {
        analogWrite(  RED_LED[i], 255 - redPWM  );
        analogWrite(GREEN_LED[i], 255 - greenPWM);
        analogWrite( BLUE_LED[i], 255 - bluePWM );
    }
}


#endif //SYSTEM_CONTROLLER_FUNCTIONS
