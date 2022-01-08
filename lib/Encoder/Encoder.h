#ifndef __ENCODER_H
#define __ENCODER_H

#include <Arduino.h>

// GPIO5 --> D1 --> CLK     GPIO4 --> D2 --> DT    GPIO0 --> D3 --> SW
#define EC_CLKPIN 5
#define EC_DTPIN  4
#define EC_SWPIN  0

void EC11_GPIO_INIT(void);
signed char EC11_Scan(unsigned char EC11_Type);
void EC11_Test(void);

#endif /* __ENCODER_H */