#ifndef __LED1_H
#define __LED1_H

#include <Arduino.h>

// LED 接在板子的io2上
#define LED1PIN 2

void LED1_GPIO_INIT(void);
void LED1_twinkle(void);


#endif /** __LED1_H **/