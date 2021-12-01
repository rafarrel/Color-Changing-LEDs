#ifndef DEFINED_TYPES_H
#define DEFINED_TYPES_H

/* 
 * Colors that the "RGB" LED can change to. 
 */
typedef enum COLOR_NAME {
    Cyan = 0, 
  Purple = 1,
   Green = 2,
  Orange = 3,
     Red = 4
} Color;

/* 
 * PWM values for the Red, Green, and Blue LEDS making up each
 * "RGB" LED for a specified color.
 */
typedef struct LED_PWMS {
  int   redPWM;
  int greenPWM;
  int  bluePWM;
} LEDColor;

#endif //DEFINED_TYPES_H