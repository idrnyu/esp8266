#ifndef __LED_H
#define __LED_H

#include <Arduino.h>

// LED 接在板子的io2上
#define LEDPIN 2

void LED_GPIO_INIT(void);
void LED_twinkle(void);

#endif
