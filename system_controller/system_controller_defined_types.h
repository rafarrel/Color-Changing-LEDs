#ifndef SYSTEM_CONTROLLER_DEFINED_TYPES_H
#define SYSTEM_CONTROLLER_DEFINED_TYPES_H


/* 
 * Collection of PWM values for the Red, Green, and Blue LEDS in
 * an "RGB" LED. Each collection of PWM values represents a color
 * that the "RGB" LED can turn to.
 */
typedef struct LED_PWMS {
    int   redPWM;
    int greenPWM;
    int  bluePWM;
} LEDColor;


#endif //SYSTEM_CONTROLLER_DEFINED_TYPES_H