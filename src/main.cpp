// #include <ESP8266WiFi.h>

// #include "../lib/LED/led.h"  // 普通延时LED闪烁，调用的delay函数
// #include "../lib/LED1/led1.h"  // 使用millis函数获取当前的系统运行时长 非阻塞
// #include "../lib/KEY/key.h"  // 普通按钮开关实验
#include "../lib/KEY1/key1.h"  // 简单的按键扫描实验


void setup()
{
  // LED_GPIO_INIT();
  // LED1_GPIO_INIT();
  // KEY_GPIO_INIT();
  KEY_GPIO_INIT();
}

void loop()
{
  // LED_twinkle();
  // LED1_twinkle();
  // KEY_Task();
  KEY_Test();
}