#ifndef __KEY1_H
#define __KEY1_H

#include <Arduino.h>

#define KEYPIN 0
#define LEDPIN 2

void KEY_GPIO_INIT(void);
u8 KRY_Scan(u8);

void KEY_Test(void);

#endif /* __KEY1_H */