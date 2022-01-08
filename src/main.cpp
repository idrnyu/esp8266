// #include <ESP8266WiFi.h>
// #include <HardwareSerial.h>

// #include "../lib/LED/led.h"  // 普通延时LED闪烁，调用的delay函数
// #include "../lib/LED1/led1.h"  // 使用millis函数获取当前的系统运行时长 非阻塞
// #include "../lib/KEY/key.h"  // 普通按钮开关实验
// #include "../lib/KEY1/key1.h"  // 简单的按键扫描实验
#include "../lib/Encoder/Encoder.h" // 简单的EC11编码器实验

void setup()
{
    // Serial.begin(9600); // 初始化串口 波特率9600
    // Serial.print("初始化中...\r\n");
    // LED_GPIO_INIT();
    // LED1_GPIO_INIT();
    // KEY_GPIO_INIT();
    // KEY_GPIO_INIT();
    EC11_GPIO_INIT();
}

void loop()
{
    // LED_twinkle();
    // LED1_twinkle();
    // KEY_Task();
    // KEY_Test();
    EC11_Test();
}
