#ifndef __KEY_H
#define __KEY_H

#include <Arduino.h>

#define KEYPIN 0
#define KLEDPIN 2

void KEY_GPIO_INIT(void);
void KEY_Task(void);

#endif /*  __KEY_H  */